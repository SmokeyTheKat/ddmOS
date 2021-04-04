#ifndef __ddclib_ddcPrint_h__
#define __ddclib_ddcPrint_h__

#include <kernel/vga.h>
#include <ddcLib/ddcString.h>

void ddPrint(void* data, long length);
void ddPrints(char* data);
void ddPrint_char(char c);
void ddPrint_int(long v);

#endif
