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

	int ccc = 0;
	vga_draw_char(g_vgaFont.hashtag, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.H, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.E, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.L, ccc, 4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.L, ccc, 4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.O, ccc, 4, 45);
	ccc+=5;
	ccc+=5;
	vga_draw_char(g_vgaFont.T, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.H, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.E, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.R, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.E, ccc,  4, 45);
	ccc+=5;
	ccc+=5;
	vga_draw_char(g_vgaFont.H, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.O, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.W, ccc,  4, 45);
	ccc+=5;
	ccc+=5;
	vga_draw_char(g_vgaFont.A, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.R, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.E, ccc,  4, 45);
	ccc+=5;
	ccc+=5;
	vga_draw_char(g_vgaFont.Y, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.O, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.U, ccc,  4, 45);
	ccc+=5;
	vga_draw_char(g_vgaFont.questmk, ccc,  4, 45);
	ccc+=5;
	ccc+=5;

/*


	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			vga_set_pixel(i, j, i+j);

*/


	for(;;) asm volatile("hlt");
}
