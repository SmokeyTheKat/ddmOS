#ifndef __ddclib_ddcMem_h__
#define __ddclib_ddcMem_h__

void ddMem_copy(void* vdst, const void* vsrc, long len)
{
	char* dst = (char*)vdst;
	char* src = (char*)vsrc;
	for (int i = 0; i < len; i++)
	{
		dst[i] = src[i];
	}
}

#endif
