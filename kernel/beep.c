#include "../include/kernel/beep.h"

void system_beep(uint32t frequency)
{
	//set pit
	uint32t rfreq = 1193180 / frequency;
	system_outb(0x43, 0xB6);
	system_outb(0x42, (uint8t)rfreq);
	system_outb(0x42, (uint8t)(rfreq >> 8));

	//start pc beeper
	uint8t val = system_inb(0x61);
	if (val != (val | 3))
		system_outb(0x61, val | 3);
}

void system_cbeep(uint32t frequency, double length)
{
	system_beep(frequency);
	system_sleep_seconds(length);
	system_nobeep();
}

void system_nobeep(void)
{
	system_outb(0x61, (system_inb(0x61) & 0xFC));
}
