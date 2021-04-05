ENTRY(_start)

SECTIONS
{
	. = 1M;
	.boot :
	{
		KEEP(*(.multiboot))
	}
	.idt BLOCK(0x1000) :
	{
		_idt = .;
		. = . + 0x1000;
	}
	.text :
	{
		*(.text)
	}
}
