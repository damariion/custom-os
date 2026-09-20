SECTION .nasm

global kpmio_ins8
kpmio_ins8:
    
    xor eax, eax
    mov dx, [esp+0x4]
    in al, dx
    ret

global kpmio_ins16
kpmio_ins16:

    xor eax, eax
    mov dx, [esp+0x4]
    in ax, dx
    ret

global kpmio_out8
kpmio_out8:

    mov eax, [esp+0x8]
    mov edx, [esp+0x4]
    out dx, al
    ret

global kpmio_out16
kpmio_out16:

    mov eax, [esp+0x8]
    mov edx, [esp+0x4]
    out dx, ax
    ret