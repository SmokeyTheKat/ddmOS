ENTRY(_start)

SECTIONS
{
	. = 0x1000000;
	.text BLOCK(0x1000) :
	{
		*(.text)
	}
	.data BLOCK(0x1000) :
	{
		*(.data)
	}
}
