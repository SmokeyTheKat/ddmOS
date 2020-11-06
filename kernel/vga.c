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

void vga_draw_char(uint8t* f, int x, int y, uint8t c)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (((f[i] >> j) & 1U) == 1) vga_set_pixel(x+j, y+i, c);
		}
	}
}

