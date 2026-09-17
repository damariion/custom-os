BITS 32
extern conclear
extern intnew
extern kmain

_kmain:

    call conclear
    call intnew
    call kmain
    
    jmp $
 
times 32 - ($-$$) db 0