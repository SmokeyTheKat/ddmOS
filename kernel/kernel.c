//kernel.h    the main kernel script
#include "../include/kernel/kernel.h"
#include "../include/kernel/tty.h"
#include "../include/kernel/keyboard.h"
#include "../include/kernel/system.h"
#include "../include/kernel/interrupt.h"
#include "../include/kernel/serial.h"
#include "../include/kernel/vga.h"
#include "../include/kernel/fonts.h"
#include "../include/kernel/memBank.h"

#include "../include/ddcLib/ddcString.h"
#include "../include/ddcDef.h"

#include <stdint.h>

volatile unsigned char g_scanCodeState;

void kernel_ps1(struct ddtty* _dt)
{
	ddtty_set_color(_dt, 15, 0);
	ddtty_write_cstring(_dt, "[");
	ddtty_set_color(_dt, 48, 0);
	ddtty_write_cstring(_dt, "DDM");
	ddtty_set_color(_dt, 38, 0);
	ddtty_write_cstring(_dt, "OS");
	ddtty_set_color(_dt, 15, 0);
	ddtty_write_cstring(_dt, "]> ");
	ddtty_set_color(_dt, _dt->fgColor, _dt->bgColor);
	ddtty_draw_cursor(_dt);
}


typedef unsigned char byte;

int cur;

struct ddtty g_selectedTerm;
struct ddtty g_kernelTerm1;
struct ddtty g_kernelTerm2;

extern void kmain(void)
{
	init_memBank();
	init_vga();
	init_fonts();

	g_kernelTerm1 = make_ddtty(make_ddIVec2(5, 5), make_ddIVec2(150, 190), make_ddIVec2(30,38), 44, 0);
	g_kernelTerm2 = make_ddtty(make_ddIVec2(160, 5), make_ddIVec2(150, 190), make_ddIVec2(30,38), 32, 0);

	g_selectedTerm = g_kernelTerm1;


	int borderColor = 16*2+12;
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 200; y++)
			vga_set_pixel(x, y, borderColor);
	for (int x = 320-2; x < 321; x++)
		for (int y = 0; y < 200; y++)
			vga_set_pixel(x, y, borderColor);

	for (int x = 159-3; x < 158; x++)
		for (int y = 0; y < 200; y++)
			vga_set_pixel(x, y, borderColor);

	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 320; x++)
			vga_set_pixel(x, y, borderColor);
	for (int y = 200-2; y < 201; y++)
		for (int x = 0; x < 320; x++)
			vga_set_pixel(x, y, borderColor);


	ddtty_write_cstring(&g_kernelTerm2, "STARTING KERNEL TERM 2\n\n");
	ddtty_write_cstring(&g_kernelTerm2, "RUNNING TESTS...\n");
/*

	ddtty_write_cstring(&g_kernelTerm2, "S1 = MAKE(CHAR, 5) = \"TESTS\"\n");
	char* s1 = make(char, 6);
	s1[0] = 'T';
	s1[1] = 'E';
	s1[2] = 'S';
	s1[3] = 'T';
	s1[4] = 'S';
	s1[5] = '\0';

	ddtty_write_cstring(&g_kernelTerm2, "S2 = MAKE(CHAR, 3) = \"YES\"\n");
	char* s2 = make(char, 4);
	s2[0] = 'Y';
	s2[1] = 'E';
	s2[2] = 'S';
	s2[3] = '\0';

	ddtty_write_cstring(&g_kernelTerm2, "PRINT S1 \"");
	ddtty_write_cstring(&g_kernelTerm2, s1);
	ddtty_write_cstring(&g_kernelTerm2, "\"\n");

	ddtty_write_cstring(&g_kernelTerm2, "PRINT S2 \"");
	ddtty_write_cstring(&g_kernelTerm2, s2);
	ddtty_write_cstring(&g_kernelTerm2, "\"\n");

	ddtty_write_cstring(&g_kernelTerm2, "RAZE(S2)\n");

	ddtty_write_cstring(&g_kernelTerm2, "S3 = MAKE(CHAR, 3) = \"RAP\"\n");
	char* s3 = make(char, 4);
	s2[0] = 'R';
	s2[1] = 'A';
	s2[2] = 'P';
	s2[3] = '\0';

	ddtty_write_cstring(&g_kernelTerm2, "PRINT S1 \"");
	ddtty_write_cstring(&g_kernelTerm2, s1);
	ddtty_write_cstring(&g_kernelTerm2, "\"\n");

	ddtty_write_cstring(&g_kernelTerm2, "PRINT S3 \"");
	ddtty_write_cstring(&g_kernelTerm2, s2);
	ddtty_write_cstring(&g_kernelTerm2, "\"\n");

	raze(s1);
	raze(s2);
	raze(s3);

	char* s0 = make(char, 30000);
	char* s1 = make(char, 30000);
	char* s2 = make(char, 30000);
	raze(s2);
	char* s3 = make(char, 300000);
	raze(s3);
	char* s4 = make(char, 30000);
	raze(s4);
	char* s5 = make(char, 30000);
	raze(s5);
	char* s6 = make(char, 3000);
	raze(s6);
	char* s7 = make(char, 30000);
	raze(s7);
	char* s8 = make(char, 300);
	raze(s8);
	char* s9 = make(char, 4);
	raze(s9);
	char* s10 = make(char, 4);
	raze(s10);
	char* s11 = make(char, 200);

*/

	kernel_ps1(&g_kernelTerm2);



	//ddtty_redraw(&g_selectedTerm);

	//ddtty_write_cstring(&g_selectedTerm, "STARTING MEMORY BANK...\n");

	//ddtty_write_cstring(&g_selectedTerm, "STARTING VGA DRIVERS...\n");
	//ddtty_write_cstring(&g_selectedTerm, "STARTING DDTTY...\n");
	//ddtty_write_cstring(&g_selectedTerm, "STARTING SYSTEM FONTS...\n");


	//ddtty_write_cstring(&g_selectedTerm, "READYING SERIAL COMS...\n");
	init_serial(PORT_COM1);

	//ddtty_write_cstring(&g_selectedTerm, "STARTING IDT...\n");
	init_idt();

	//ddtty_write_cstring(&g_selectedTerm, "STARTING KEYBOARD LAYOUTS...\n");
	init_keyboard();

	//ddtty_write_cstring(&g_selectedTerm, "STARTING DDMOS INTERRUPTER...\n\n");
	init_ddsh();

	//ddtty_write_cstring(&g_selectedTerm, "WELCOME TO DDMOS.\n\n");

	//kernel_ps1(&g_selectedTerm);

	for(;;) asm volatile("hlt");
}
