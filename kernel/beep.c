#include <kernel/beep.h>
#include <kernel/system.h>

void pcspk_play(uint32t freq)
{
	uint32t div = 1193180 / freq;
	system_outb(0x43, 0xb6);
	system_outb(0x42, (uint8t) (div));
	system_outb(0x42, (uint8t) (div >> 8));

	uint8t tmp = system_inb(0x61);
	if (tmp != (tmp | 3))
	{
		system_outb(0x61, tmp | 3);
	}
}

void pcspk_nosound(void)
{
	system_outb(0x61, (system_inb(0x61) & 0xfc));
}

void beep(uint32t freq, uint32t time)
{
	pcspk_play(freq);
	system_sleep(time);
	pcspk_nosound();
}
