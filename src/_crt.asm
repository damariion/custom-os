BITS 32
extern __console_clear
extern kmain

start:
    call __console_clear
    call kmain
    jmp $

times 32 - ($-$$) db 0