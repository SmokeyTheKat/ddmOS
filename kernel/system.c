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

