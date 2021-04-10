#include <kernel/kernel.h>
#include <kernel/vga.h>
#include <ddcLib/ddcPrint.h>
#include <ddcLib/ddcString.h>
#include <kernel/idt.h>
#include <kernel/keyboard.h>
#include <kernel/tty.h>
#include <kernel/mmap.h>
#include <kernel/mbank.h>
#include <kernel/pci.h>
#include <boot/multiboot.h>

extern const char test[];

void print_mode(void)
{
	char buf[10];

	ddPrints("\x1b[38;5;2mkernel is running in ");
	ddPrints(make_ddString_from_buf_from_int(buf, 10, sizeof(long)*8).cstr);
	ddPrints(" bit mode\n");
}

void kmain(void)
{
	init_vga();
	init_mmap_regions();
	init_mbank();
	vga_clear();
	print_mode();
	//init_pci();
	init_idt();
	init_keyboard();
	init_vgatty();

	while (1) asm ("hlt");
}
