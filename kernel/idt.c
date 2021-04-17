#include <kernel/idt.h>
#include <kernel/system.h>
#include <ddcLib/ddcDef.h>
#include <ddcLib/ddcPrint.h>

extern uint64t isr1;
extern uint64t isr105;
uint64t* isrs[256] = {0};

extern struct IDT64 _idt[256];

extern void load_idt(void);

void isr_void(void)
{
	//system_outb(0x20, 0x20);
}

void init_idt(void)
{
	for (int i = 0; i < 256; i++)
		isrs[i] = &isr1;
	isrs[0x69] = &isr105;
	for (int i = 0; i < 256; i++)
	{
		_idt[i].zero = 0;
		_idt[i].offset_low = (uint16t)(((uint64t)isrs[i] & 0x000000000000ffff));
		_idt[i].offset_mid = (uint16t)(((uint64t)isrs[i] & 0x00000000ffff0000) >> 16);
		_idt[i].offset_high = (uint32t)(((uint64t)isrs[i] & 0xffffffff00000000) >> 32);
		_idt[i].ist = 0;
		_idt[i].selector = 0x08;
		_idt[i].types_attr = 0x8e;
	}
	system_outb(0x21, 0xfd);
	system_outb(0xa1, 0xff);
	load_idt();
}

void(*isr_handlers[256])(void) = {
	[0 ... 255]=isr_void,
};

void idt_set_isr(int isr, void(*fun)(void))
{
	isr_handlers[isr] = fun;
}

extern void isr1_handler(void)
{
	//ddPrints("INT 0x01\n");
	system_outb(0x20, 0x20);
	isr_handlers[1]();
}
extern void isr105_handler(void)
{
	//ddPrints("int 0x80\n");
	isr_handlers[0x69]();
	system_outb(0x20, 0x20);
}
