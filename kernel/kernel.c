#include <ddcLib/ddcPrint.h>
#include <ddcLib/ddcString.h>
#include <ddcLib/ddcMem.h>
#include <ddcLib/ddcColors.h>
#include <boot/multiboot.h>
#include <kernel/kernel.h>
#include <kernel/vga.h>
#include <kernel/idt.h>
#include <kernel/keyboard.h>
#include <kernel/tty.h>
#include <kernel/mmap.h>
#include <kernel/beep.h>
#include <kernel/mbank.h>
#include <kernel/pci.h>
#include <kernel/fs.h>
#include <kernel/syscall.h>
#include <kernel/mouse.h>
#include <elf.h>

extern const char test[];

void print_mode(void)
{
	char buf[10];

	ddPrints(CFWHITE"KERNEL IS RUNNING IN ");
	ddPrints(make_ddString_from_buf_from_int(buf, 10, sizeof(long)*8).cstr);
	ddPrints(" BIT MODE\n");
}

void kmain(void)
{
	init_vga();
	vga_clear();
	print_mode();

	ddPrints("GETTING USABLE MEMORY REGIONS...");
	init_mmap_regions();
	ddPrints(" ["CFGREEN"DONE"CFWHITE"]\n");

	init_mbank();

	ddPrints("LOCATING FS...");
	init_fs();
	ddPrints(" ["CFGREEN"DONE"CFWHITE"] - FS FOUND AT ");
	ddPrint_int(fs_get_location());
	ddPrints("\n");


	ddPrints("INITIALIZING INTERRUPTS...");
	init_idt();
	init_syscalls();
	ddPrints(" ["CFGREEN"DONE"CFWHITE"]\n");
	//init_pci();
	init_mouse();

	extern void syscall_test(void);
	//syscall_test();


	ddPrints("INITIALIZING KEYBOARD...");
	init_keyboard();
	ddPrints(" ["CFGREEN"DONE"CFWHITE"]\n");

	ddPrints("INITIALIZING TTY...");
	init_vgatty();
	ddPrints(" ["CFGREEN"DONE"CFWHITE"]\n");

	start_vgatty();

	while (1) asm ("hlt");
}
