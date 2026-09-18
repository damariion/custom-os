[BITS 16]
[ORG  0x7C00]

    cli ; disable interrupts
    
    ; stabilise segment registers
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    jmp far 0x0:init.real

init.real:

    ; enable A20
    mov ax, 0x2401
    int 0x15

    ; switch to protected mode
    lgdt [gdt.desc]
    mov eax, cr0
    or al, 1
    mov cr0, eax

    jmp 0x8:init.protected

; global descriptor table
gdt.null:
    dd 0
    dd 0
gdt.code: ; 0x08
    dw 0xFFFF ; base
    dw 0      ; limit
    db 0
    dw 0xCF9A ; access (along with some legacy stuff)
    db 0
gdt.data: ; 0x10
    dw 0xFFFF
    dw 0
    db 0
    dw 0xCF92
    db 0
gdt.desc:
    dw gdt.desc - gdt.null - 1
    dd gdt.null

[BITS 32]
init.protected:

    ; stabilise segments
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov fs, ax
    mov gs, ax
    mov ebp, 0x9FC00
    mov esp, ebp

    ; place kernel in memory
    mov cl, 31
    mov edi, 0x100000
    call disk.read

    jmp edi

disk.read:; (count->cl, output->edi)

    cld
    pushad

    ; set: mode, drive, LBA[24:27]
    mov dx, 0x1F6
    mov al, 0xE0
    out dx, al

    ; set: sector amount
    mov dx, 0x1F2
    mov al, cl
    out dx, al

    ; set: LBA = 1
    mov dx, 0x1F5
    xor al, al
    out dx, al
    dec dx
    out dx, al
    dec dx
    inc al
    out dx, al

    ; set: mode = READ
    mov dx, 0x1F7
    mov al, 0x20
    out dx, al

    ; backup: counter
    mov bl, cl

.next:
    mov dx, 0x1F7
.busy:
    
    in al, dx
    test al, 0x80 ; BSY
    jne .busy
    test al, 0x01 ; ERR (e.g. disk < cl*512)
    jnz .done
    test al, 0x08 ; DRQ
    je .busy

    ; copy: disk -> edi
    mov dx, 0x1F0
    mov ecx, 256
    rep insw

    dec bl
    jnz .next

.done:

    popad
    ret

times 510 - ($-$$) db 0
dw 0xAA55