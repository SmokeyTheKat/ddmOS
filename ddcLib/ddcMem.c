#include <ddcLib/ddcMem.h>

void ddMem_copy(void* vdst, void* vsrc, long len)
{
	char* dst = (char*)vdst;
	char* src = (char*)vsrc;
	for (long i = 0; i < len; i++)
	{
		dst[i] = src[i];
	}
}
