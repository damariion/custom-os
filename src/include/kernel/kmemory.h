#pragma once
#include <types/rational.h>

#define KMEMORY_UNIT_KB         1024
#define KMEMORY_UNIT_MB         (KMEMORY_UNIT_KB * 1024)
#define KMEMORY_UNIT_HEAP_BLOCK (KMEMORY_UNIT_KB * 4)

#define KMEMORY_IS_HEAP_BLOCK_ALIGNED(ptr) \
    ((ptr % KMEMORY_UNIT_HEAP_BLOCK) == 0)

#define KMEMORY_PTR_HEAP_TABLE  0x7E00  
#define KMEMORY_PTR_HEAP        0x1000000

#define KMEMORY_HEAP_ENTRY_TYPE_FREE  0x00
#define KMEMORY_HEAP_ENTRY_TYPE_TAKEN 0x01
#define KMEMORY_HEAP_ENTRY_MASK_FIRST 0x40
#define KMEMORY_HEAP_ENTRY_MASK_JOINT 0x80

typedef u8 kmemory_heap_table_entry_t;

typedef struct __attribute__((packed)) {
    kmemory_heap_table_entry_t* entries;
    u32 size;
} kmemory_heap_table_t;

typedef struct __attribute__((packed)) {
    void* start;
    kmemory_heap_table_t* table;
} kmemory_heap_t;

kmemory_heap_t       kmemory_kheap;
kmemory_heap_table_t kmemory_kheap_table;

int  kmemory_heap_create(kmemory_heap_t* heap, void* start, void* stop, kmemory_heap_table_t* table);
void kmemory_heap_init(void* ptr, u32 bytes);