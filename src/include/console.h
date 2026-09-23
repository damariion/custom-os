#pragma once
#include <types/rational.h>

#define CONSOLE_PTR_MEMORY ((u16*)0xB8000)
#define CONSOLE_MAX_WIDTH  80
#define CONSOLE_MAX_HEIGHT 25
#define CONSOLE_MAX_CELLS (CONSOLE_MAX_WIDTH * CONSOLE_MAX_HEIGHT)

typedef struct { u8 x; u8 y; } axes_t;
typedef enum { black, blue, green, cyan, red, magenta, brown, white, grey, yellow = 0xE } colour_t;

void conclear(void);
void conwrite(const char* text);

void concursor(axes_t axes);
void concolour(colour_t colour);