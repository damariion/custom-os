SECTION .nasm

global intnull
intnull: 
    iret

global intpic
intpic:
    
    ; init
    mov al, 0x11
    out 0x20, al
    out 0xA0, al
    
    ; set: bases = 0x20, 0x28
    mov al, 0x20
    out 0x21, al
    mov al, 0x28
    out 0xA1, al

    ; set: IDs = master, slave
    mov al, 0x04
    out 0x21, al
    mov al, 0x02
    out 0xA1, al

    ; set: mode to 8086
    mov al, 0x01
    out 0x21, al
    out 0xA1, al

    ret