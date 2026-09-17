#pragma once
#include <types/rational.h>
#include <memory.h>

#define KERNEL_SELECTOR_CODE 0x08
#define KERNEL_SELECTOR_DATA 0x10
#define KERNEL_MAX_IDT_COUNT 256

typedef struct __attribute__((packed)) {
    u16 offset_1;
    u16 selector;
    u8  reserved;
    u8  attributes;
    u16 offset_2;
} interrupt_descriptor_t;

typedef struct __attribute__((packed)) {
    u16 limit;
    u32 base;
} interrupt_registry_t;

typedef struct __attribute__((packed)) {
    u32 ip;
    u32 cs;
    u32 flags;
    u32 sp;
    u32 ss;
} interrupt_frame_t;

void intnew(void);
void intset(u8 index, u8 ring, void* callback);