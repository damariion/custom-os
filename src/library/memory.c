#include <memory.h>

void memset(void* dest, u8 value, u32 size)
{
    for (u32 i = 0; i < size; i++)
        ((char*)dest)[i] = (char)value;
}

void memcpy(void* dest, void* source, u32 size)
{
    for (u32 i = 0; i < size; i++)
        ((char*)dest)[i] = ((char*)source)[i];
}

bool memcmp(void* ptr_1, void* ptr_2, u32 size)
{
    for (u32 i = 0; i < size; i++)
    {
        if (((char*)ptr_1)[i] != ((char*)ptr_2)[i])
            return false;
    }
    
    return true; 
}