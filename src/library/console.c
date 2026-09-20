#include "types/rational.h"
#include <console.h>

axes_t   console_static_axes = {.x = 0, .y = 0};
colour_t console_static_tone = white;

void __console_set_axes(axes_t axes, char value)
{
    CONSOLE_PTR_MEMORY[(axes.y * CONSOLE_MAX_WIDTH) + axes.x] 
        = (console_static_tone << 8) | value;
}

void clear(void)
{
    for (u16 x = 0; x < CONSOLE_MAX_WIDTH; x++)
    {
        for (u16 y = 0; y < CONSOLE_MAX_HEIGHT; y++)
            __console_set_axes((axes_t){.x = x, .y = y}, 0);
    }
}

void print(const char* text)
{
    while (*text)
    {
        if (*text == '\n')
        {
            console_static_axes.y++;
            console_static_axes.x=0;
            text++; continue;
        }

        __console_set_axes(console_static_axes, *text++);
        console_static_axes.x++;
    }
}