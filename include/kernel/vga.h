#ifndef __ddmos_vga_h__
#define __ddmos_vga_h__

#include "./system.h"


#define VGA_WIDTH 320
#define VGA_HEIGHT 200
#define VGA_COLOR_COUNT 256

extern char* g_vgaBuffer;// pointer to vga video memory

void init_vga(void);
void vga_set_pixel(int x, int y, uint8t color);
void vga_draw_char(uint8t* fontChar, int x, int y, uint8t c);

#endif
