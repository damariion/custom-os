#pragma once
#include <stdint.h>
#include <stdbool.h>

void memset(void* dest, uint8_t value, uint32_t count);
void memcpy(void* dest, void* source, uint32_t size);
bool memcmp(void* ptr_1, void* ptr_2, uint32_t size);