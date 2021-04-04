#include <kernel/vga.h>
#include <kernel/system.h>
#include <ddcLib/ddcMem.h>

const sizet TERMWIDTH  = 80;
const sizet TERMHEIGHT = 25;

VColor VColor_indexes[16] = {
	VCOLOR_BLACK,
	VCOLOR_BLUE,
	VCOLOR_GREEN,
	VCOLOR_CYAN,
	VCOLOR_RED,
	VCOLOR_MAGENTA,
	VCOLOR_YELLOW,
	VCOLOR_LIGHT_GREY,
	VCOLOR_DARK_GREY,
	VCOLOR_LIGHT_BLUE,
	VCOLOR_LIGHT_GREEN,
	VCOLOR_LIGHT_CYAN,
	VCOLOR_LIGHT_RED,
	VCOLOR_LIGHT_MAGENTA,
	VCOLOR_LIGHT_BROWN,
	VCOLOR_WHITE,
};

sizet g_term_x;
sizet g_term_y;
short g_term_color;
VColor g_term_bgcolor;
VColor g_term_fgcolor;
short* g_term_buffer;

void vga_set_fgcolor(VColor fg)
{
	g_term_fgcolor = fg;
	g_term_color = (uint16t)(fg | g_term_bgcolor << 4);
}
void vga_set_bgcolor(VColor bg)
{
	g_term_bgcolor = bg;
	g_term_color = (uint16t)(g_term_fgcolor | bg << 4);
}
void vga_set_color(VColor fg, VColor bg)
{
	g_term_fgcolor = fg;
	g_term_bgcolor = bg;
	g_term_color = (uint16t)(fg | bg << 4);
}

void vga_enable_cursor(void)
{
	system_outb(0x3D4, 0x0A);
	char cs = system_inb(0x3D5) & 0x1F;
	system_outb(0x3D4, 0x0A);
	system_outb(0x3D5, cs | 0x20);
}

void vga_disable_cursor(void)
{
	system_outb(0x3D4, 0x0A);
	system_outb(0x3D5, 0x20);
}
void vga_update_cursor(void)
{
	uint16t _p = (g_term_y*TERMWIDTH)+g_term_x;
	system_outb(0x3D4, 0x0F);
	system_outb(0x3D5, (uint8t)(_p & 0xFF));
	system_outb(0x3D4, 0x0E);
	system_outb(0x3D5, (uint8t)((_p >> 8) & 0xFF));
}
void vga_move_cursor(int x, int y)
{
	uint16t _p = (y*TERMWIDTH)+x;
	system_outb(0x3D4, 0x0F);
	system_outb(0x3D5, (uint8t)(_p & 0xFF));
	system_outb(0x3D4, 0x0E);
	system_outb(0x3D5, (uint8t)((_p >> 8) & 0xFF));
}

sizet vgarlen(const char* _c)
{
	sizet _o = 0;
	while(_c[_o]) _o++;
	return _o;
}

void init_vga(void)
{
	g_term_y = 0;
	g_term_x = 0;
	g_term_color = VCOLOR_WHITE;
	g_term_buffer = (short*)0xb8000;

	vga_move_cursor(0,0);

	for (sizet i = 0; i < TERMHEIGHT; i++)
	{
		for (sizet j = 0; j < TERMWIDTH; j++)
		{
			g_term_buffer[j+TERMWIDTH] = g_term_color | ' ';
		}
	}
}

void vga_clear(void)
{
	for (int x = 0; x < TERMWIDTH; x++)
	{
		for (int y = 0; y < TERMHEIGHT; y++)
		{
			g_term_buffer[y*TERMWIDTH + x] = 0;
			g_term_buffer[y*TERMWIDTH + x+1] = 0;
		}
	}
			
}

void vga_write_char(char _c)
{
	g_term_buffer[(g_term_y * TERMWIDTH) + g_term_x] = g_term_color | _c;
	if (++g_term_x == TERMWIDTH)
	{
		g_term_x = 0;
		if (++g_term_y == TERMHEIGHT)
			g_term_y = 0;
	}	
	vga_move_cursor(g_term_x, g_term_y);
}

void vga_scroll_down(int n)
{
	for (int i = 0; i < TERMHEIGHT-n; i++)
	{
		ddMem_copy(&g_term_buffer[(i * TERMWIDTH)], &g_term_buffer[(i * TERMWIDTH) + (TERMWIDTH*n)], TERMWIDTH*2);
	}
}

void vga_write(const char* s, sizet len)
{
	for (sizet i = 0; i < len; i++)
	{
		if (s[i] == '\b')
		{
			g_term_x--;
			vga_write_char(' ');
			g_term_x--;
			vga_move_cursor(g_term_x, g_term_y);
		}
		else if (s[i] == '\n')
		{
			g_term_x = 0;
			g_term_y++;
			if (g_term_y+1 >= TERMHEIGHT)
			{
				vga_scroll_down(1);
				g_term_y--;
			}
			vga_move_cursor(g_term_x, g_term_y);
		}
		else if (s[i] == '\x1b')
		{
			if ((*(int*)(&s[i]) == *(int*)"\x1b[38") ||
			    (*(int*)(&s[i]) == *(int*)"\x1b[48"))
			{
				char type = s[i+2];
				i += 4;
				if (*(short*)(&s[i]) == *(short*)";5")
				{
					i += 2;
					if (s[i] == ';')
					{
						i++;
						int v = 0;
						long numlen = 0;
						while (s[i + (++numlen)] != 'm');
						if (numlen == 2)
						{
							v += 10 * (s[i]-'0');
							v += (s[i+1]-'0');
							i++;
						}
						else v = (s[i]-'0');

						if (type == '3')
							vga_set_fgcolor(VColor_indexes[v]);
						else if (type == '4')
							vga_set_bgcolor(VColor_indexes[v]);
						i++;
					}
				}
			}
		}
		else vga_write_char(s[i]);
	}
}
