#include "../include/kernel/vga.h"

char* const g_vgaBuffer = (char* const)0xA0000; //vga video memory

void init_vga(void) {};

void vga_set_pixel(int x, int y, uint8t color)
{
	g_vgaBuffer[y*VGA_WIDTH+x] = color;
}

void vga_draw_char(byte* charFont, int x, int y, uint8t color)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (((charFont[i] >> j) & 1U) == 1) vga_set_pixel(x+j, y+i, color);
		}
	}
}
