#ifndef __ddclib_ddcPrint_h__
#define __ddclib_ddcPrint_h__

#include <kernel/vga.h>
#include <ddcString.h>

void ddPrint(void* data, long length)
{
	vga_write(data, length);
}
void ddPrints(char* data)
{
	long length = cstring_length(data);
	vga_write(data, length);
}

#endif
