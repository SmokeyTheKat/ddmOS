//kernel.h    the main kernel script
#include "../include/kernel/kernel.h"
#include "../include/kernel/tty.h"
#include "../include/kernel/keyboard.h"
#include "../include/kernel/system.h"
#include "../include/kernel/interrupt.h"
#include "../include/kernel/serial.h"
#include "../include/kernel/vga.h"
#include "../include/kernel/fonts.h"

#include "../include/ddcLib/ddcString.h"

volatile unsigned char g_scanCodeState;

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

#include "../include/ddcLib/make.h"

typedef unsigned char byte;

int cur;

void draw_char(uint8t* v)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (((v[i] >> j) & 1U) == 1) vga_set_pixel(cur+j, i, j+i);
		}
	}
	cur+=7;
}

extern void kmain(void)
{
	//init_term();
	//term_write_cstring("Initializing VGA text drivers...\n");

	init_vga();
	init_fonts();

	//term_write_cstring("Readying serial communication on COM1...\n");
	init_serial(PORT_COM1);

	//term_write_cstring("Initializing interrupt descriptor table...\n");
	init_idt();

	//term_write_cstring("Initializing keyboard layouts...\n");
	//init_keyboard();

	//term_write_cstring("Starting ddmOS interrupter...\n\n");
	//init_ddsh();

	//term_write_cstring("Welcome to ddmOS.\n\n");
	//kernel_ps1();

	draw_char(vgaFontDefault.W);
	draw_char(vgaFontDefault.I);
	draw_char(vgaFontDefault.L);
	draw_char(vgaFontDefault.L);
	draw_char(vgaFontDefault.I);
	draw_char(vgaFontDefault.A);
	draw_char(vgaFontDefault.M);



	for(;;) asm volatile("hlt");
}
