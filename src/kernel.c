#include <interrupt.h>
#include <console.h>

__attribute__((interrupt)) 
void keyboard_interrupt(interrupt_frame_t* frame)
{
    
    conwrite("Keyboard pressed!");

}

void kmain()
{

    intset(0x21, 0, &keyboard_interrupt);
    __asm__("int $0x21");

}