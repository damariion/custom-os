#include <console.h>
#include <stdint.h>

#define  __VGA ((uint16_t*)0xB8000)
axes_t   __console_state_axes = {.x = 0, .y = 0};
colour_t __console_state_tone = white;

void __console_set_axes(axes_t axes, char value)
{
    __VGA[(axes.y * CONSOLE_MAX_WIDTH) + axes.x] = 
        (__console_state_tone << 8) | value;
}

void colour(colour_t colour)
{
    __console_state_tone = colour;
}

void clear(void)
{
    for (uint16_t x = 0; x < CONSOLE_MAX_WIDTH; x++)
    {
        for (uint16_t y = 0; y < CONSOLE_MAX_HEIGHT; y++)
            __console_set_axes((axes_t){.x = x, .y = y}, 0);
    }
}

void print(const char* text)
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