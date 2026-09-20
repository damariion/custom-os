#include <kernel/kinterrupt.h>

extern void kinterrupt_nullfn(void);
kinterrupt_descriptor_t kinterrupt_descriptors[KINTERRUPT_MAX_IDT_COUNT];
kinterrupt_registry_t   kinterrupt_registry;

void kinterrupt_reset_registry()
{
    // prevent triple fault from unimplemented interrupts
    for (int i = 0; i < KINTERRUPT_MAX_IDT_COUNT; i++)
        kinterrupt_set_descriptor(i, 0, &kinterrupt_nullfn);

    // register the (now empty) interrupt descriptor registry
    kinterrupt_registry.size = sizeof(kinterrupt_descriptors) - 1;
    kinterrupt_registry.base = (u32)kinterrupt_descriptors;

    // point the CPU to the registry
    __asm__("lidt kinterrupt_registry");
}

void kinterrupt_set_descriptor(u8 index, u8 ring, void* callback)
{
    kinterrupt_descriptor_t* descriptor = 
        &kinterrupt_descriptors[index];
    
    descriptor->reserved = 0x0;
    descriptor->selector = 0x8;
    descriptor->offset_1 = (u32)callback & 0xffff;
    descriptor->offset_2 = (u32)callback >> 16;
    descriptor->attributes = 0b10001110 | ring << 5;
}