#include <interrupt.h>

interrupt_descriptor_t __interrupt_descriptors[KERNEL_MAX_IDT_COUNT];
interrupt_registry_t   __interrupt_registry;

void intnew()
{
    memset(__interrupt_descriptors, 0, 
        sizeof(__interrupt_descriptors));

    __interrupt_registry.limit = sizeof(__interrupt_descriptors) - 1;
    __interrupt_registry.base = (u32)__interrupt_descriptors;
    
    __asm__("lidt [__interrupt_registry]");
}

void intset(u8 index, u8 ring, void* callback)
{
    interrupt_descriptor_t* descriptor = 
        &__interrupt_descriptors[index];
    
    descriptor->reserved = 0x0;
    descriptor->selector = 0x8;
    descriptor->offset_1 = (u32)callback & 0xffff;
    descriptor->offset_2 = (u32)callback >> 16;
    descriptor->attributes = 0b10001110 | ring << 5;
}