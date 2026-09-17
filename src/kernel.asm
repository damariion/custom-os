BITS 32
extern clear
extern kmain

_kmain:

    call clear
    call kmain
    jmp $

times 32 - ($-$$) db 0