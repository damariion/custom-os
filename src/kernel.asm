BITS 32

extern kinterrupt_reset_registry
extern kinterrupt_reset_controller

extern clear
extern kmain

_clean:

    ; stabilise interrupts
    call kinterrupt_reset_registry
    call kinterrupt_reset_controller
    sti

    ; clear console
    call clear

_kmain:

    call kmain
    jmp $
 
times 128 - ($-$$) db 0