#include "../include/kernel/vga.h"

char* g_vgaBuffer;

void init_vga(void)
{
	g_vgaBuffer = (char*)0xA0000;
}

void vga_set_pixel(int x, int y, uint8t c)
{
	g_vgaBuffer[y*VGA_WIDTH+x] = c;
}
