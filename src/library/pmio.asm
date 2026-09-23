SECTION .nasm

global ins8
ins8:
    
    xor eax, eax
    mov dx, [esp+0x4]
    in al, dx
    ret

global ins16
ins16:

    xor eax, eax
    mov dx, [esp+0x4]
    in ax, dx
    ret

global out8
out8:

    mov eax, [esp+0x8]
    mov edx, [esp+0x4]
    out dx, al
    ret

global out16
out16:

    mov eax, [esp+0x8]
    mov edx, [esp+0x4]
    out dx, ax
    ret