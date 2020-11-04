#include "../include/kernel/serial.h"
/*
void init_serial(uint16t cport)
{
	system_outb(cport + 1, 0x00);
	system_outb(cport + 3, 0x80);
	system_outb(cport + 0, 0x03);
	system_outb(cport + 1, 0x00);
	system_outb(cport + 3, 0x03);
	system_outb(cport + 2, 0xC7);
	system_outb(cport + 4, 0x0B);
}

int serial_received(uint16t cport)
{
	return system_inb(cport + 5) & 1;
}

char serial_read(uint16t cport)
{
	while (!serial_received(cport));
	return system_inb(cport);
}

int serial_transmit_is_empty(uint16t cport)
{
	return system_inb(cport + 5) & 0x20;
}

void serial_write(char c, uint16t cport)
{
	while (!serial_transmit_is_empty(cport));
	system_outb(cport, c);
}
*/
