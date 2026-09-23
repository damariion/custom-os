#pragma once
#include <types/rational.h>
#include <pmio.h>

#define MAX_IDT_COUNT 256

typedef struct __attribute__((packed)) {
    u16 offset_1;
    u16 selector;
    u8  reserved;
    u8  attributes;
    u16 offset_2;
} interrupt_descriptor_t;

typedef struct __attribute__((packed)) {
    u16 size;
    u32 base;
} interrupt_registry_t;

typedef struct __attribute__((packed)) {
    u32 ip;
    u32 cs;
    u32 flags;
    u32 sp;
    u32 ss;
} interrupt_frame_t;

extern interrupt_descriptor_t interrupt_descriptors[MAX_IDT_COUNT];
extern interrupt_registry_t   interrupt_registry;

void intrst();
void intset(u8 index, u8 ring, void* callback);