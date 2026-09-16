#pragma once
#include <stdint.h>

#define CONSOLE_MAX_WIDTH  80
#define CONSOLE_MAX_HEIGHT 25
#define CONSOLE_MAX_CELLS (CONSOLE_MAX_WIDTH * CONSOLE_MAX_HEIGHT)

typedef struct { uint8_t x; uint8_t y; } axes_t;
typedef enum { black, blue, green, cyan, red, magenta, brown, white, grey, yellow = 0xE } colour_t;

extern void clear(void);
extern void print(const char* text);
extern void colour(colour_t colour);