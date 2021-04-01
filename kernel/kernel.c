#include <kernel/vga.h>
#include <kernel/tty.h>
#include <ddcPrint.h>

void kmain(void) 
{
	init_vga();

	int abit = sizeof(long)*8;

	ddPrints("kernel is running in ");
	if (abit == 64)
		ddPrints("64");
	else if (abit == 32)
		ddPrints("32");
	ddPrints(" mode\n");

	ddPrints("\x1b[38;5;0mOMG Hi :)\n");
	ddPrints("\x1b[38;5;1mOMG Hi :)\n");
	ddPrints("\x1b[38;5;2mOMG Hi :)\n");
	ddPrints("\x1b[38;5;3mOMG Hi :)\n");
	ddPrints("\x1b[38;5;4mOMG Hi :)\n");
	ddPrints("\x1b[38;5;5mOMG Hi :)\n");
	ddPrints("\x1b[38;5;6mOMG Hi :)\n");
	ddPrints("\x1b[38;5;7mOMG Hi :)\n");
	ddPrints("\x1b[38;5;8mOMG Hi :)\n");
	ddPrints("\x1b[38;5;9mOMG Hi :)\n");
	ddPrints("\x1b[38;5;10mOMG Hi :)\n");
	ddPrints("\x1b[38;5;11mOMG Hi :)\n");
	ddPrints("\x1b[38;5;12mOMG Hi :)\n");
	ddPrints("\x1b[38;5;13mOMG Hi :)\n");
	ddPrints("\x1b[38;5;14mOMG Hi :)\n");
	ddPrints("\x1b[38;5;15mOMG Hi :)\n");

	ddPrints("\x1b[38;5;1m\n");

	ddPrints("\x1b[48;5;0mOMG Hi :)\n");
	ddPrints("\x1b[48;5;1mOMG Hi :)\n");
	ddPrints("\x1b[48;5;2mOMG Hi :)\n");
	ddPrints("\x1b[48;5;3mOMG Hi :)\n");
	ddPrints("\x1b[48;5;4mOMG Hi :)\n");
	ddPrints("\x1b[48;5;5mOMG Hi :)\n");
	ddPrints("\x1b[48;5;6mOMG Hi :)\n");
	ddPrints("\x1b[48;5;7mOMG Hi :)\n");
	ddPrints("\x1b[48;5;8mOMG Hi :)\n");
	ddPrints("\x1b[48;5;9mOMG Hi :)\n");
	ddPrints("\x1b[48;5;10mOMG Hi :)\n");
	ddPrints("\x1b[48;5;11mOMG Hi :)\n");
	ddPrints("\x1b[48;5;12mOMG Hi :)\n");
	ddPrints("\x1b[48;5;13mOMG Hi :)\n");
	ddPrints("\x1b[48;5;14mOMG Hi :)\n");
	ddPrints("\x1b[48;5;15mOMG Hi :)\n");
}
