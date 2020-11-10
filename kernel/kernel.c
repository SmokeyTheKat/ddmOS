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

#include <stdint.h>

volatile unsigned char g_scanCodeState;

void kernel_ps1(struct ddtty* _dt)
{
	ddtty_set_color(_dt, 15, 0);
	ddtty_write_cstring(_dt, "[");
	ddtty_set_color(_dt, 48, 0);
	ddtty_write_cstring(_dt, "ddm");
	ddtty_set_color(_dt, 38, 0);
	ddtty_write_cstring(_dt, "OS");
	ddtty_set_color(_dt, 15, 0);
	ddtty_write_cstring(_dt, "]> ");
}

#include "../include/ddcLib/make.h"

typedef unsigned char byte;

int cur;

struct ddtty g_mainTerm;

extern void kmain(void)
{
	init_vga();
	init_fonts();

	g_mainTerm = make_ddtty(make_ddIVec2(0, 0), make_ddIVec2(320, 200), make_ddIVec2(64,40), 15, 0);
	ddtty_write_cstring(&g_mainTerm , "Initializing VGA drivers...\n");
	ddtty_write_cstring(&g_mainTerm , "Initializing ddtty...\n");
	ddtty_write_cstring(&g_mainTerm , "Initializing system fonts...\n");


	ddtty_write_cstring(&g_mainTerm , "Readying serial communication on COM1...\n");
	init_serial(PORT_COM1);

	ddtty_write_cstring(&g_mainTerm , "Initializing interrupt descriptor table...\n");
	init_idt();

	ddtty_write_cstring(&g_mainTerm , "Initializing keyboard layouts...\n");
	init_keyboard();

	ddtty_write_cstring(&g_mainTerm , "Starting ddmOS interrupter...\n\n");
	init_ddsh();

	ddtty_write_cstring(&g_mainTerm , "Welcome to ddmOS.\n\n");

	kernel_ps1(&g_mainTerm );

	for(;;) asm volatile("hlt");
}
