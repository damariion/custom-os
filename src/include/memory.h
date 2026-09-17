#pragma once
#include <types/rational.h>
#include <types/boolean.h>

void memset(void* dest, u8 value, u32 count);
void memcpy(void* dest, void* source, u32 size);
bool memcmp(void* ptr_1, void* ptr_2, u32 size);