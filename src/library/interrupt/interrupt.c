#include <interrupt.h>

extern void intnull(void);
interrupt_descriptor_t interrupt_descriptors[MAX_IDT_COUNT];
interrupt_registry_t   interrupt_registry;

void intrst()
{
    // prevent triple fault from unimplemented interrupts
    for (int i = 0; i < MAX_IDT_COUNT; i++)
        intset(i, 0, &intnull);

    // register the (now empty) interrupt descriptor registry
    interrupt_registry.size = sizeof(interrupt_descriptors) - 1;
    interrupt_registry.base = (u32)interrupt_descriptors;

    // point the CPU to the registry
    __asm__("lidt interrupt_registry");
}

void intset(u8 index, u8 ring, void* callback)
{
    interrupt_descriptor_t* descriptor = 
        &interrupt_descriptors[index];
    
    descriptor->reserved = 0x0;
    descriptor->selector = 0x8;
    descriptor->offset_1 = (u32)callback & 0xffff;
    descriptor->offset_2 = (u32)callback >> 16;
    descriptor->attributes = 0b10001110 | ring << 5;
}