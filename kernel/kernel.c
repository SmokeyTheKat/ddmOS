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
extern void kmain(void)
{
	init_term();
	term_write_cstring("Welcome to ddmOS.\n\n");
	kernel_ps1();

	//init_gdt();
	//init_idt();
	//init_isrs();
	//init_irq();
	//init_keyboard();


	for(;;) asm volatile("hlt");
}
