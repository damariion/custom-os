#pragma once
#include <types/basic.h>

typedef enum {
    black,
    blue,
    green,
    cyan,
    red,
    magenta,
    brown,
    white,
    grey,
    yellow = 0xE
} colour_t;

typedef struct
{
    u8 x;
    u8 y;
} axis_t;

struct __console_namespace {
    void (*clear)();
    void (*write)(cstr text);
    void (*colour)(colour_t name);
}; extern const struct __console_namespace Console;