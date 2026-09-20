#pragma once
#include <types/rational.h>
#include <kernel/kpmio.h>

#define KINTERRUPT_MAX_IDT_COUNT 256

typedef struct __attribute__((packed)) {
    u16 offset_1;
    u16 selector;
    u8  reserved;
    u8  attributes;
    u16 offset_2;
} kinterrupt_descriptor_t;

typedef struct __attribute__((packed)) {
    u16 size;
    u32 base;
} kinterrupt_registry_t;

typedef struct __attribute__((packed)) {
    u32 ip;
    u32 cs;
    u32 flags;
    u32 sp;
    u32 ss;
} kinterrupt_frame_t;

extern kinterrupt_descriptor_t kinterrupt_descriptors[KINTERRUPT_MAX_IDT_COUNT];
extern kinterrupt_registry_t   kinterrupt_registry;

void kinterrupt_reset_registry();
void kinterrupt_set_descriptor(u8 index, u8 ring, void* callback);