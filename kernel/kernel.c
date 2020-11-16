//kernel.h    the main kernel script
#include "../include/kernel/kernel.h"
#include "../include/kernel/drivers/tty.h"
#include "../include/kernel/io/keyboard.h"
#include "../include/kernel/sys/system.h"
#include "../include/kernel/sys/beep.h"
#include "../include/kernel/int/interrupt.h"
#include "../include/kernel/io/serial.h"
#include "../include/kernel/drivers/vga.h"
#include "../include/kernel/sys/fonts.h"
#include "../include/kernel/mm/memBank.h"

#include "../include/ddcLib/ddcString.h"
#include "../include/ddcDef.h"

volatile unsigned char g_scanCodeState;

void kernel_ps1(struct ddtty* _dt)
{
	ddtty_set_color(_dt, 15, 0);
	ddtty_write_cstring(_dt, "[");
	ddtty_set_color(_dt, 9, 0);
	ddtty_write_cstring(_dt, "DDM");
	ddtty_set_color(_dt, 38, 0);
	ddtty_write_cstring(_dt, "OS");
	ddtty_set_color(_dt, 15, 0);
	ddtty_write_cstring(_dt, "]> ");
	ddtty_set_color(_dt, _dt->fgColor, _dt->bgColor);
	ddtty_draw_cursor(_dt);
}

static void kernel_load_screen(void)
{
	for (int x = 0; x < 320; x++)
		vga_set_pixel(x, 5, 4);
	for (int x = 0; x < 320; x++)
		vga_set_pixel(x, 200-5, 4);

	for (int x = 0; x < 320; x++)
		vga_set_pixel(x, 10, 2);
	for (int x = 0; x < 320; x++)
		vga_set_pixel(x, 200-10, 2);

	for (int x = 0; x < 320; x++)
		vga_set_pixel(x, 15, 1);
	for (int x = 0; x < 320; x++)
		vga_set_pixel(x, 200-15, 1);

	byte logo[35*28] = {
		1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,
		1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,1,0,0,0,0,
		1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,1,0,0,1,1,1,0,0,
		1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0,
		1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,1,1,1,0,
		1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
};

	int sc = 5;
	for (int x = 0; x < 35; x++)
	{
		for (int y = 0; y < 28; y++)
		{
/*
			for (int mx = 0; mx < sc; mx++)
				for (int my = 0; my < sc; my++)
					if (logo[(y)*35+x] == 1) vga_set_pixel(72+x*sc+mx, 35+my+y*sc, 44);
*/
			for (int mx = 0; mx < sc; mx++)
			{
				if (logo[y*35+x] == 1)
				{
					if (y >= 9)
						vga_set_pixel(72+x*sc+mx, 35+y*sc, 44);
					else
					{
						if (x < 23)
							vga_set_pixel(72+x*sc+mx, 35+y*sc, 9);
						else
							vga_set_pixel(72+x*sc+mx, 35+y*sc, 4);
					}
				}
			}
		}
	}

	system_cbeep(196, 0.8);
	system_cbeep(185, 0.2);
	system_cbeep(185, 0.2);
	system_sleep_seconds(0.13);
	system_cbeep(147, 0.4);
	system_cbeep(165, 0.2);
	system_cbeep(96, 0.6);
	system_sleep_seconds(1.5);
}

static void kernel_draw_borders(void)
{
	int borderColor = 16*2+12;
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 200; y++)
			vga_set_pixel(x, y, borderColor);
	for (int x = 320-2; x < 321; x++)
		for (int y = 0; y < 200; y++)
			vga_set_pixel(x, y, borderColor);

	for (int x = 159-3; x < 158; x++)
		for (int y = 20+0; y < 200; y++)
			vga_set_pixel(x, y, borderColor);

	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 320; x++)
			vga_set_pixel(x, 20+y, borderColor);
	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 320; x++)
			vga_set_pixel(x, y, borderColor);
	for (int y = 200-2; y < 201; y++)
		for (int x = 0; x < 320; x++)
			vga_set_pixel(x, y, borderColor);
}

typedef unsigned char byte;

int cur;

struct ddtty g_selectedTerm;
struct ddtty g_kernelTerm1;
struct ddtty g_kernelTerm2;

extern void kmain(void)
{
	init_vga();

	init_idt();

	kernel_load_screen();

	vga_clear();

	init_fonts();

	g_kernelTerm1 = make_ddtty(make_ddIVec2(5, 20+5), make_ddIVec2(150, 190-20), make_ddIVec2(30,38), 44, 0);
	g_kernelTerm2 = make_ddtty(make_ddIVec2(160, 20+5), make_ddIVec2(150, 190-20), make_ddIVec2(30,38), 32, 0);

	g_selectedTerm = g_kernelTerm2;

	init_memBank();

	kernel_draw_borders();

	ddtty_write_cstring(&g_selectedTerm, "STARTING MEMORY BANK...\n");

	ddtty_write_cstring(&g_selectedTerm, "STARTING VGA DRIVERS...\n");
	ddtty_write_cstring(&g_selectedTerm, "STARTING DDTTY...\n");
	ddtty_write_cstring(&g_selectedTerm, "STARTING SYSTEM FONTS...\n");

	ddtty_write_cstring(&g_selectedTerm, "READYING SERIAL COMS...\n");
	init_serial(PORT_COM1);

	ddtty_write_cstring(&g_selectedTerm, "STARTING IDT...\n");

	ddtty_write_cstring(&g_selectedTerm, "STARTING KEYBOARD LAYOUTS...\n");
	init_keyboard();

	ddtty_write_cstring(&g_selectedTerm, "STARTING DDMOS INTERRUPTER...\n\n");
	init_ddsh();

	g_selectedTerm = g_kernelTerm1;

	ddtty_write_cstring(&g_selectedTerm, "WELCOME TO DDMOS!\n\n");

	kernel_ps1(&g_selectedTerm);

	for(;;) asm volatile("hlt");
}
