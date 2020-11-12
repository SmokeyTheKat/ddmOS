#include "../include/kernel/system.h"

uint8t system_inb(uint16t port)
{
	uint8t output;
	asm volatile("inb %1, %0" : "=a"(output) : "d"(port));
	return output;
}
/*
uint16t system_inw(uint16t port)
{
	uint16t output;
	asm volatile("inw %1, %0" : "=a"(output) : "d"(port));
	return output;
}
*/
uint32t system_inl(uint16t port)
{
	uint32t output;
	asm volatile("inl %1, %0" : "=a"(output) : "d"(port));
	return output;
}

void system_outb(uint16t port, uint8t value)
{
	asm volatile("outb %0, %1" : : "a"(value), "d"(port));
}
/*
void system_outw(uint16t port, int16t value)
{
	asm volatile("outw %0, %1" : : "a"(value), "d"(port));
}
*/
void system_outd(uint16t port, uint32t value)
{
	asm volatile("outl %0, %1" : : "a"(value), "d"(port));
}

void system_halt(void)
{
	asm volatile("hlt;");
}

void system_await_input(void)
{
	asm volatile("jmp 1f;"
		     "1:jmp 2f;"
		     "2:");
}

void system_reboot(void)
{
	uint8t _g = 0x02;
	while (_g & 0x02)
		_g = system_inb(0x64);
	system_outb(0x64, 0xFE);
	system_halt();
}

uint64t system_get_rdtsc(void)
{
	uint32t _l;
	uint32t _h;
	asm volatile("rdtsc" : "=a"(_l), "=d"(_h));
	return (((uint64t)_h << 32) | _l);
}

void system_sleep(uint32t sleepTime)
{
	for(;;)
	{
		asm volatile("nop");
		sleepTime--;
		if (sleepTime <= 0) break;
	}
}

/*
void system_set_vga_mode(uint8t _move)
{
	//asm volatile("mov 
}
*/


//temp memset
void* memset(void* _d, int8t _v, sizet _c)
{
	char* d = (char*)_d;
	for (;_c!=0;_c--)*d++ = _v;
	return _d;
}

