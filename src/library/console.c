#include <console.h>

#define VGA ((u16*)0xB8000)
#define CONSOLE_MAX_WIDTH  80
#define CONSOLE_MAX_HEIGHT 25
#define CONSOLE_MAX_CELLS (CONSOLE_MAX_WIDTH * CONSOLE_MAX_HEIGHT)

axis_t   __console_vga_axis   = {.x=0, .y=0};
colour_t __console_vga_colour = white;

// primitive methods
void __console_set_axis(chr c, axis_t i)
{
    VGA[(i.y*CONSOLE_MAX_WIDTH) + i.x] = 
        (__console_vga_colour << 8) | c;
}

// standard methods
void __console_colour(colour_t colour)
{ 
    __console_vga_colour = colour; 
}

void __console_clear()
{
    for (u16 x = 0; x < CONSOLE_MAX_WIDTH; x++)
    {
        for (u16 y = 0; y < CONSOLE_MAX_HEIGHT; y++)
            __console_set_axis('\0', (axis_t){.x=x, .y=y});
    }
}

void __console_write(cstr text)
{
    while (*text)
    {
        if (*text == '\n')
        {
            __console_vga_axis.y++;
            __console_vga_axis.x=0;
            text++; continue;
        }

        __console_set_axis(*text++, __console_vga_axis);
        __console_vga_axis.x++;
    }
}

const struct __console_namespace Console = {
    .clear  = &__console_clear,
    .write  = &__console_write,
    .colour = &__console_colour
};