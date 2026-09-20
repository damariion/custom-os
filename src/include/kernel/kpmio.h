#pragma once
#include <types/rational.h>

u8 kpmio_ins8(u16 port);
u8 kpmio_ins16(u16 port);

void kpmio_out8(u16 port, u8 value);
void kpmio_out16(u16 port, u16 value);