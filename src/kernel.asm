BITS 32

extern intrst
extern intpic

extern conclear
extern kmain

_clean:

    ; stabilise interrupts
    call intrst
    call intpic    
    sti

    ; clear console
    call conclear

_kmain:

    call kmain
    jmp $
 
times 128 - ($-$$) db 0