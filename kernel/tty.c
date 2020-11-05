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
const sizet TERM_WIDTH  = 80;
const sizet TERM_HEIGHT = 25;

sizet g_termYPos;// current pos of cursor y
sizet g_termXPos;// current pos of cursor x
short g_termColor;// current terminal color
short* g_termBuffer;// pointer to vga video memory

void term_delete_line(void)
{
	for (sizet j = 0; j < TERM_WIDTH; j++)
	{
		g_termBuffer[(g_termYPos) * TERM_WIDTH + j] = g_termColor | ' ';
	}
}

void term_pop_top(void)
{
	short line[TERM_WIDTH];
	for (sizet i = 1; i < TERM_HEIGHT; i++)
	{
		for (sizet j = 0; j < TERM_WIDTH; j++)
		{
			line[j] = g_termBuffer[i*TERM_WIDTH + j];
		}
		for (sizet j = 0; j < TERM_WIDTH; j++)
		{
			g_termBuffer[(i-1)*TERM_WIDTH + j] = line[j];
		}
	}
	for (sizet j = 0; j < TERM_WIDTH; j++)
	{
		g_termBuffer[(TERM_HEIGHT-1) * TERM_WIDTH + j] = g_termColor | ' ';
	}
}

void term_clear(void)
{
	for (sizet i = 0; i < TERM_HEIGHT; i++)
	{
		for (sizet j = 0; j < TERM_WIDTH; j++)
		{
			g_termBuffer[i * TERM_WIDTH + j] = g_termColor | ' ';
		}
	}
	g_termYPos = 0;
	g_termXPos = 0;
}

void term_set_color(VColor fg, VColor bg)
{
	g_termColor = (uint16t)(fg | bg << 4);
}

void term_enable_cursor(uint8t cs, uint8t ce)
{
	system_outb(0x3D4, 0x0A);
	system_outb(0x3D5, (system_inb(0x3D6) & 0xC0) | cs);

	system_outb(0x3D4, 0x0B);
	system_outb(0x3D5, (system_inb(0x3D5) & 0xE0) | ce);
}

void term_disable_cursor(void)
{
	system_outb(0x3D4, 0x0A);
	system_outb(0x3D5, 0x20);
}
void term_update_cursor(void)
{
	uint16t _p = (g_termYPos*TERM_WIDTH)+g_termXPos;
	system_outb(0x3D4, 0x0F);
	system_outb(0x3D5, (uint8t)(_p & 0xFF));
	system_outb(0x3D4, 0x0E);
	system_outb(0x3D5, (uint8t)((_p >> 8) & 0xFF));
}
void term_move_cursor(int x, int y)//y is row
{
	uint16t _p = (y*TERM_WIDTH)+x;
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
	g_termYPos = 0;
	g_termXPos = 0;
	g_termColor = VCOLOR_WHITE;// white
	g_termBuffer = (short*)0xb8000;// mem addr of vga video memory

	term_move_cursor(0,0);

	//term_disable_cursor();
	term_enable_cursor(13, 15);

	//init buffer with ' '
	term_clear();
}

void term_write_char(char _c)
{
	if (_c == '\n')
	{
		g_termXPos = 0;
		g_termYPos++;
		if (g_termYPos == TERM_HEIGHT)// if y pos is about to pass terminal height
		{
			term_pop_top();
			g_termYPos--;
		}
	}
	else
	{
		g_termBuffer[(g_termYPos * TERM_WIDTH) + g_termXPos] = g_termColor | _c;
		if (++g_termXPos == TERM_WIDTH)// if x pos is about to pass terminal width
		{
			g_termXPos = 0;
			if (++g_termYPos == TERM_HEIGHT)// if y pos is about to pass terminal height
			{
				term_pop_top();
				g_termYPos--;
			}
		}	
	}
	term_move_cursor(g_termXPos, g_termYPos);
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
