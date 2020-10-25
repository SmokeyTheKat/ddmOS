//tty.h   script for writing to and managing the tty
//
//
//
//
//
//
//
//
//
//
//

#include "../include/kernel/tty.h"

//terminal is 80 by 25
const sizet TERMWIDTH  = 80;
const sizet TERMHEIGHT = 25;

sizet g_termRow;// current pos of cursor y
sizet g_termColumn;// current pos of cursor x
short g_termColor;// current terminal color
short* g_termBuffer;// pointer to vga video memory

void term_set_color(VColor fg, VColor bg)
{
	g_termColor = (uint16t)(fg | bg << 4);
}

void term_enable_cursor(void)
{
	system_outb(0x3D4, 0x0A);
	char cs = system_inb(0x3D5) & 0x1F;
	system_outb(0x3D4, 0x0A);
	system_outb(0x3D5, cs | 0x20);
}

void term_disable_cursor(void)
{
	system_outb(0x3D4, 0x0A);
	system_outb(0x3D5, 0x20);
}
void term_update_cursor(void)
{
	uint16t _p = (g_termRow*TERMWIDTH)+g_termColumn;
	system_outb(0x3D4, 0x0F);
	system_outb(0x3D5, (uint8t)(_p & 0xFF));
	system_outb(0x3D4, 0x0E);
	system_outb(0x3D5, (uint8t)((_p >> 8) & 0xFF));
}
void term_move_cursor(int x, int y)//y is row
{
	uint16t _p = (y*TERMWIDTH)+x;
	system_outb(0x3D4, 0x0F);
	system_outb(0x3D5, (uint8t)(_p & 0xFF));
	system_outb(0x3D4, 0x0E);
	system_outb(0x3D5, (uint8t)((_p >> 8) & 0xFF));
}


// temporary strlen
sizet t_strlen(const char* _c)
{
	sizet _o = 0;
	while(_c[_o]) _o++;
	return _o;
}

void init_term(void)
{
	g_termRow = 0;
	g_termColumn = 0;
	g_termColor = VCOLOR_WHITE;// white
	g_termBuffer = (short*)0xb8000;// mem addr of vga video memory

	term_move_cursor(0,0);

	//term_enable_cursor(0, TERMWIDTH);
	//term_disable_cursor();

//init buffer with ' '
	for (sizet i = 0; i < TERMHEIGHT; i++)
	{
		for (sizet j = 0; j < TERMWIDTH; j++)
		{
			g_termBuffer[j+TERMWIDTH] = g_termColor | ' ';
		}
	}
}

void term_write_char(char _c)
{
	if (_c == '\n')
	{
		g_termColumn=0;
		g_termRow++;
	}
	else
	{
		g_termBuffer[(g_termRow * TERMWIDTH) + g_termColumn] = g_termColor | _c;
		if (++g_termColumn == TERMWIDTH)// if x pos is about to pass terminal width
		{
			g_termColumn = 0;
			if (++g_termRow == TERMHEIGHT)// if y pos is about to pass terminal height
				g_termRow = 0;
		}	
	}
	term_move_cursor(g_termColumn, g_termRow);
}

void term_write(const char* _c, sizet _len)
{
	for (sizet i = 0; i < _len; i++)
		term_write_char(_c[i]);
}

void term_write_cstring(const char* _c)
{
	sizet _len = t_strlen(_c);
	term_write(_c, _len);
}
