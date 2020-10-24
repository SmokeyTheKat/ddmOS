#include "../lib/ddcDef.h"

//terminal is 80 by 25
const sizet TERMWIDTH  = 80;
const sizet TERMHEIGHT = 25;

sizet g_termRow;// current pos of cursor y
sizet g_termColumn;// current pos of cursor x
short g_termColor;// current terminal color
short* g_termBuffer;// pointer to vga video memory

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
	g_termColor = 0x0F00;// white
	g_termBuffer = (short*)0xb8000;// mem addr of vga video memory

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

extern void kmain()
{
	init_term();
	term_write_cstring("Welcome to ddmOS.\n\n[ddmOS]> _");
}
