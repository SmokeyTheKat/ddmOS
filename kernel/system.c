#include <kernel/system.h>

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

void system_halt(void)
{
	asm volatile("hlt;");
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

void system_sleep(uint32t _t)
{
	for(;;)
	{
		asm volatile("nop");
		if (_t-- <= 0) break;
	}
}


void system_sleep_seconds(double sleepTime)
{
	system_sleep((uint32t)(sleepTime * (double)500000000));
}



//temp memset
void* memset(void* _d, int8t _v, sizet _c)
{
	char* d = (char*)_d;
	for (;_c!=0;_c--)*d++ = _v;
	return _d;
}

