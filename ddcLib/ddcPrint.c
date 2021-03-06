#include <ddcLib/ddcPrint.h>

void ddPrint(void* data, long length)
{
	vga_write(data, length);
}
void ddPrints(char* data)
{
	long length = cstring_length(data);
	ddPrint(data, length);
}
void ddPrint_char(char c)
{
	ddPrint(&c, 1);
}
void ddPrint_int(long v)
{
	char buf[128];
	ddString str = make_ddString_from_buf_from_int(buf, 128, v);
	ddPrint(str.cstr, str.length);
}
