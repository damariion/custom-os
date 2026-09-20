#include <kernel/kmemory.h>

int kmemory_heap_create(kmemory_heap_t* heap, void* start, void* stop, kmemory_heap_table_t* table)
{
    return 0;
}

void kmemory_heap_init(void* ptr, u32 bytes)
{
    kmemory_kheap_table.entries = (kmemory_heap_table_entry_t*)KMEMORY_PTR_HEAP_TABLE;
    kmemory_kheap_table.size    = (bytes / KMEMORY_UNIT_HEAP_BLOCK);
    kmemory_kheap.table = &kmemory_kheap_table;
    kmemory_kheap.start = ptr; 

    if (kmemory_heap_create(&kmemory_kheap, ptr, 
        (ptr + bytes), &kmemory_kheap_table) < 0)
    {

    }
}