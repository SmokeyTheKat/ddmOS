ENTRY(_start)
OUTPUT_FORMAT("binary")

SECTIONS
{
	. = 0x7c00;

	.text :
	{
		*(._start)
		*(.text)
	}
	.data :
	{
		*(.data)
	}
	.idt BLOCK(0x1000) :
	{
		_idt = .;
		. = . + 0x1000;
	}
	.rodata :
	{
		*(.rodata)
	}
	.bss :
	{
		*(.bss)
	}
}
