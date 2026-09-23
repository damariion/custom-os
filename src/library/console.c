#include "types/rational.h"
#include <console.h>

axes_t   __console_state_axes = {.x = 0, .y = 0};
colour_t __console_state_tone = white;

void __console_set_axes(axes_t axes, char value)
{
    CONSOLE_PTR_MEMORY[(axes.y * CONSOLE_MAX_WIDTH) + axes.x] 
        = (__console_state_tone << 8) | value;
}

void concursor(axes_t axes)     { __console_state_axes = axes; }
void concolour(colour_t colour) { __console_state_tone = colour; }

void conclear(void)
{
    for (u16 x = 0; x < CONSOLE_MAX_WIDTH; x++)
    {
        for (u16 y = 0; y < CONSOLE_MAX_HEIGHT; y++)
            __console_set_axes((axes_t){.x = x, .y = y}, 0);
    }
}

void conwrite(const char* text)
{
    while (*text)
    {
        if (*text == '\n')
        {
            __console_state_axes.y++;
            __console_state_axes.x=0;
            text++; continue;
        }

        __console_set_axes(__console_state_axes, *text++);
        __console_state_axes.x++;
    }
}