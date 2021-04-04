/*ENTRY(_start)*/
OUTPUT_FORMAT("binary")

SECTIONS
{
	. = 0x8000;

	.text : ALIGN(0x1000)
	{
		*(._start)
		*(.text)
	}
	.data : ALIGN(0x1000)
	{
		*(.data)
	}
	.idt BLOCK(0x1000) : ALIGN(0x1000)
	{
		_idt = .;
		. = . + 0x1000;
	}
	.rodata : ALIGN(0x1000)
	{
		*(.rodata)
	}
	.bss : ALIGN(0x1000)
	{
		*(.bss)
	}
}
