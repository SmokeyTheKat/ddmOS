#ifndef __ddmos_vga_h__
#define __ddmos_vga_h__

#include "./system.h"


#define VGA_WIDTH 320
#define VGA_HEIGHT 200
#define VGA_COLOR_COUNT 256

extern char* const g_vgaBuffer;// pointer to vga video memory

void init_vga(void);
void vga_clear(void);
void vga_set_pixel(int x, int y, uint8t color);
void vga_draw_char(byte* charFont, int x, int y, uint8t fgColor, uint8t bgColor);// draws 4 element array of bytes using the first 4 bits of each byte


#endif
