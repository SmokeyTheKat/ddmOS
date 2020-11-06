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

	vga_draw_char(g_vgaFont.W, 0,  0, 32);
	vga_draw_char(g_vgaFont.I, 6,  0, 32);
	vga_draw_char(g_vgaFont.L, 12, 0, 32);
	vga_draw_char(g_vgaFont.L, 18, 0, 32);
	vga_draw_char(g_vgaFont.I, 24, 0, 32);
	vga_draw_char(g_vgaFont.A, 30, 0, 32);
	vga_draw_char(g_vgaFont.M, 36, 0, 32);



	for(;;) asm volatile("hlt");
}
