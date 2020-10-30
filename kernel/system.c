#include "../include/kernel/system.h"

uint8t system_inb(uint16t _port)
{
	uint8t _o;
	asm volatile("inb %1, %0" : "=a"(_o) : "d"(_port));
	return _o;
}

void system_outb(uint16t _port, uint8t _v)
{
	asm volatile("outb %0, %1" : : "a"(_v), "d"(_port));
}

void system_await_input(void)
{
	asm volatile(   "jmp 1f;"
			"1:jmp 2f;"
			"2:");
}

uint64t system_get_rdtsc(void)
{
	uint32t _l;
	uint32t _h;
	asm volatile("rdtsc" : "=a"(_l), "=d"(_h));
	return (((uint64t)_h << 32) | _l);
}

void system_sleep(uint32t _t)
{
	for(;;)
	{
		asm volatile("nop");
		_t--;
		if (_t <= 0) break;
	}
}


//temp memset
void* memset(void* _d, int8t _v, sizet _c)
{
	char* d = (char*)_d;
	for (;_c!=0;_c--)*d++ = _v;
	return _d;
}

