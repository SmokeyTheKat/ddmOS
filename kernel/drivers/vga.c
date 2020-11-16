#include "../../include/kernel/drivers/vga.h"

char* const g_vgaBuffer = (char* const)0xA0000; //vga video memory

void init_vga(void) {};

void vga_set_pixel(int x, int y, uint8t color)
{
	g_vgaBuffer[y*VGA_WIDTH+x] = color;
}

void vga_clear(void)
{
	for (int i = 0; i < 320*VGA_WIDTH+320; i++)
		g_vgaBuffer[i] = 0;
}

void vga_draw_char(byte* charFont, int x, int y, uint8t fgColor, uint8t bgColor)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (((charFont[i] >> j) & 1U) == 1) vga_set_pixel(x+j, y+i, fgColor);
			if (((charFont[i] >> j) & 1U) == 0) vga_set_pixel(x+j, y+i, bgColor);
		}
	}
}

