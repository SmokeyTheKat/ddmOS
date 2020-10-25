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

char kernel_get_input(void)
{
	char _o = 0;
	while ((_o = system_inb(KEYBOARD_PORT)) != 0)
		if (_o > 0) return _o;
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
	char ch = 0;
	char kc = 0;
	uint32t cw = 0x00000000;
	uint32t kw = 0xEFFFFFFF;
	uint32t st = 0x00000FFF;
	uint32t spt = 0x005FFFFF;
	char com[25];
	
	do
	{
		kc = kernel_get_input();
		if (kc == lk)
		{
			cw += st;
			if (cw < kw) continue;
			else kernel_sleep(spt);
		}
		else
		{
			cw = 0x00000000;
		}
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

extern void kmain()
{
	init_term();
	term_write_cstring("Welcome to ddmOS.\n\n");
	kernel_ps1();
	kernel_test_input();
}
