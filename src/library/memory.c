#include <memory.h>

void memset(void* dest, uint8_t value, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
        ((char*)dest)[i] = (char)value;
}

void memcpy(void* dest, void* source, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
        ((char*)dest)[i] = ((char*)source)[i];
}

bool memcmp(void* ptr_1, void* ptr_2, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
    {
        if (((char*)ptr_1)[i] != ((char*)ptr_2)[i])
            return false;
    }
    
    return true;
}