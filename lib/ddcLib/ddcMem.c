#include "../../include/ddcLib/ddcMem.h"

void ddMem_set(void* dest, int value, sizet length)
{
	char* cdest = (char*)dest;
	for (sizet i = 0; i < length; i++)
	{
		cdest[i] = value;
	}
}

void ddMem_copy(void* dest, const void* src, sizet length)
{
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	for (sizet i = 0; i < length; i++)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
	}
}

void ddMem_copy_setp(void* dest, const void* src, sizet step, sizet length)
{
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	for (sizet i = 0; i < length; i+=step)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
	}
}

void ddMem_copy_offset(void* dest, const void* src, sizet destOffset, sizet srcOffset, sizet length)
{
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	cdest += destOffset;
	csrc += srcOffset;
	for (sizet i = 0; i < length; i++)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
	}
}
void ddMem_copy_offset_step(void* dest, const void* src, sizet destOffset, sizet srcOffset, sizet step, sizet length)
{
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	cdest += destOffset;
	csrc += srcOffset;
	for (sizet i = 0; i < length; i+=step)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
	}
}

void ddMem_copy_step_offset(void* dest, const void* src, sizet destOffset, sizet srcOffset, sizet step, sizet stepOffset, sizet length)
{
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	cdest += destOffset;
	csrc += srcOffset;
	for (sizet i = stepOffset; i < length; i+=step)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
	}
}
