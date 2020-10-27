//kernel.h    the main kernel script
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
#include "../include/kernel/kernel.h"

void kernel_wait_io(uint32t _timerc)
{
	while(1)
	{
		asm volatile("nop");
		_timerc--;
		if (_timerc <= 0) break;
	}
}

void kernel_sleep(uint32t _timerc)
{
	kernel_wait_io(_timerc);
}

volatile unsigned char g_scanCodeState;

char kernel_get_input(void)
{
	char _o = 0;
	system_outb(0x20, 0x20);
	while ((_o = system_inb(KEYBOARD_PORT)) != 0)
	{
		if (_o > 0)
		{
			if ((_o & 128) == 128)
				g_scanCodeState = 0;
			else
				g_scanCodeState = 1;

			return _o;
		}
	}
	return _o;
}

void kernel_ps1(void)
{
	term_set_color(VCOLOR_WHITE, VCOLOR_BLACK);
	term_write_cstring("[");
	term_set_color(VCOLOR_BLUE, VCOLOR_BLACK);
	term_write_cstring("ddm");
	term_set_color(VCOLOR_RED, VCOLOR_BLACK);
	term_write_cstring("OS");
	term_set_color(VCOLOR_WHITE, VCOLOR_BLACK);
	term_write_cstring("]> ");
}

void kernel_process(char* com)
{

}

void kernel_test_input(void)
{
	char lk = 0;
	char lkc = 0;
	char ch = 0;
	char kc = 0;
	uint32t cw = 0x00000000;
	uint32t kw = 0x2FFFFFFF;
	uint32t st = 0x00000FFF;
	uint32t spt = 0x005FFFFF;
	
	do
	{
		kc = kernel_get_input();
		if (kc == lk && lkc == g_scanCodeState)
		{
			cw += st;
			if (cw < kw) continue;
			else kernel_sleep(spt);
		}
		else
		{
			cw = 0x00000000;
		}
		lkc = g_scanCodeState;
		if (kc == KEY_ENTER)
		{
			term_write_char('\n');
			kernel_ps1();
		}
		else if (kc == KEY_RIGHT)
		{
			g_termColumn++;
			term_update_cursor();
		}
		if (kc == KEY_LEFT)
		{
			g_termColumn--;
			term_update_cursor();
		}
		if (kc == KEY_UP)
		{
			g_termRow--;
			term_update_cursor();
		}
		if (kc == KEY_DOWN)
		{
			g_termRow++;
			term_update_cursor();
		}
		if (kc == KEY_BACKSPACE)
		{
			g_termColumn--;
			term_write_char(' ');
			g_termColumn--;
			term_update_cursor();
		}
		else
		{
			ch = keyboard_ascii_to_char(kc);
			term_write_char(ch);
		}
		lk = kc;
		//kernel_sleep(st);
	}while(1);
}

#include "../include/ddcLib/make.h"
extern void kmain()
{
	char* v = make(10);
	v[0] = 'y';
	v[1] = 'o';
	v[2] = ' ';
	v[3] = 't';
	v[4] = 'h';
	v[5] = 'e';
	v[6] = 'r';
	v[7] = 'e';
	v[8] = '\n';
	v[9] = '\0';
	char* d = make(13);
	d[0] = 'o';
	d[1] = 'm';
	d[2] = 'g';
	d[3] = ' ';
	d[4] = 'l';
	d[5] = 'o';
	d[6] = 'o';
	d[7] = 'k';
	d[8] = ' ';
	d[9] = 'y';
	d[10] = 'o';
	d[11] = '\n';
	d[12] = '\0';
	init_term();
	term_write_cstring(v);
	term_write_cstring(d);
	term_write_cstring("Welcome to ddmOS.\n\n");
	kernel_ps1();
	kernel_test_input();
}
