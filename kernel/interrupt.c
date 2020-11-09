#include "../include/kernel/interrupt.h"
 
static struct IDT_entry IDT[256];

static void (*interrupt_handlers[16])(void);

static void interrupt_empty_handler(void) {};

static void init_interrupt_handlers(void)
{
	interrupt_handlers[0] = interrupt_empty_handler;
	interrupt_handlers[1] = interrupt_empty_handler;
	interrupt_handlers[2] = interrupt_empty_handler;
	interrupt_handlers[3] = interrupt_empty_handler;
	interrupt_handlers[4] = interrupt_empty_handler;
	interrupt_handlers[5] = interrupt_empty_handler;
	interrupt_handlers[6] = interrupt_empty_handler;
	interrupt_handlers[7] = interrupt_empty_handler;
	interrupt_handlers[8] = interrupt_empty_handler;
	interrupt_handlers[9] = interrupt_empty_handler;
	interrupt_handlers[10] = interrupt_empty_handler;
	interrupt_handlers[11] = interrupt_empty_handler;
	interrupt_handlers[12] = interrupt_empty_handler;
	interrupt_handlers[13] = interrupt_empty_handler;
	interrupt_handlers[14] = interrupt_empty_handler;
	interrupt_handlers[15] = interrupt_empty_handler;
}

// fill idt wiht default values
static void idt_fill(void)
{
	extern int irq0(void);
	extern int irq1(void);
	extern int irq2(void);
	extern int irq3(void);
	extern int irq4(void);
	extern int irq5(void);
	extern int irq6(void);
	extern int irq7(void);
	extern int irq8(void);
	extern int irq9(void);
	extern int irq10(void);
	extern int irq11(void);
	extern int irq12(void);
	extern int irq13(void);
	extern int irq14(void);
	extern int irq15(void);

	unsigned long irq0Addr = (unsigned long)irq0; 
	IDT[32].offset_lowerbits = irq0Addr & 0xffff;
	IDT[32].selector = 0x08;
	IDT[32].zero = 0;
	IDT[32].type_attr = 0x8e;
	IDT[32].offset_higherbits = (irq0Addr & 0xffff0000) >> 16;
 
	unsigned long irq1Addr = (unsigned long)irq1; 
	IDT[33].offset_lowerbits = irq1Addr & 0xffff;
	IDT[33].selector = 0x08;
	IDT[33].zero = 0;
	IDT[33].type_attr = 0x8e;
	IDT[33].offset_higherbits = (irq1Addr & 0xffff0000) >> 16;
 
	unsigned long irq2Addr = (unsigned long)irq2; 
	IDT[34].offset_lowerbits = irq2Addr & 0xffff;
	IDT[34].selector = 0x08;
	IDT[34].zero = 0;
	IDT[34].type_attr = 0x8e;
	IDT[34].offset_higherbits = (irq2Addr & 0xffff0000) >> 16;
 
	unsigned long irq3Addr = (unsigned long)irq3; 
	IDT[35].offset_lowerbits = irq3Addr & 0xffff;
	IDT[35].selector = 0x08;
	IDT[35].zero = 0;
	IDT[35].type_attr = 0x8e;
	IDT[35].offset_higherbits = (irq3Addr & 0xffff0000) >> 16;
 
	unsigned long irq4Addr = (unsigned long)irq4; 
	IDT[36].offset_lowerbits = irq4Addr & 0xffff;
	IDT[36].selector = 0x08;
	IDT[36].zero = 0;
	IDT[36].type_attr = 0x8e;
	IDT[36].offset_higherbits = (irq4Addr & 0xffff0000) >> 16;
 
	unsigned long irq5Addr = (unsigned long)irq5; 
	IDT[37].offset_lowerbits = irq5Addr & 0xffff;
	IDT[37].selector = 0x08;
	IDT[37].zero = 0;
	IDT[37].type_attr = 0x8e;
	IDT[37].offset_higherbits = (irq5Addr & 0xffff0000) >> 16;
 
	unsigned long irq6Addr = (unsigned long)irq6; 
	IDT[38].offset_lowerbits = irq6Addr & 0xffff;
	IDT[38].selector = 0x08;
	IDT[38].zero = 0;
	IDT[38].type_attr = 0x8e;
	IDT[38].offset_higherbits = (irq6Addr & 0xffff0000) >> 16;
 
	unsigned long irq7Addr = (unsigned long)irq7; 
	IDT[39].offset_lowerbits = irq7Addr & 0xffff;
	IDT[39].selector = 0x08;
	IDT[39].zero = 0;
	IDT[39].type_attr = 0x8e;
	IDT[39].offset_higherbits = (irq7Addr & 0xffff0000) >> 16;
 
	unsigned long irq8Addr = (unsigned long)irq8; 
	IDT[40].offset_lowerbits = irq8Addr & 0xffff;
	IDT[40].selector = 0x08;
	IDT[40].zero = 0;
	IDT[40].type_attr = 0x8e;
	IDT[40].offset_higherbits = (irq8Addr & 0xffff0000) >> 16;
 
	unsigned long irq9Addr = (unsigned long)irq9; 
	IDT[41].offset_lowerbits = irq9Addr & 0xffff;
	IDT[41].selector = 0x08;
	IDT[41].zero = 0;
	IDT[41].type_attr = 0x8e;
	IDT[41].offset_higherbits = (irq9Addr & 0xffff0000) >> 16;
 
	unsigned long irq10Addr = (unsigned long)irq10; 
	IDT[42].offset_lowerbits = irq10Addr & 0xffff;
	IDT[42].selector = 0x08;
	IDT[42].zero = 0;
	IDT[42].type_attr = 0x8e;
	IDT[42].offset_higherbits = (irq10Addr & 0xffff0000) >> 16;
 
	unsigned long irq11Addr = (unsigned long)irq11; 
	IDT[43].offset_lowerbits = irq11Addr & 0xffff;
	IDT[43].selector = 0x08;
	IDT[43].zero = 0;
	IDT[43].type_attr = 0x8e;
	IDT[43].offset_higherbits = (irq11Addr & 0xffff0000) >> 16;
 
	unsigned long irq12Addr = (unsigned long)irq12; 
	IDT[44].offset_lowerbits = irq12Addr & 0xffff;
	IDT[44].selector = 0x08;
	IDT[44].zero = 0;
	IDT[44].type_attr = 0x8e;
	IDT[44].offset_higherbits = (irq12Addr & 0xffff0000) >> 16;
 
	unsigned long irq13Addr = (unsigned long)irq13; 
	IDT[45].offset_lowerbits = irq13Addr & 0xffff;
	IDT[45].selector = 0x08;
	IDT[45].zero = 0;
	IDT[45].type_attr = 0x8e;
	IDT[45].offset_higherbits = (irq13Addr & 0xffff0000) >> 16;
 
	unsigned long irq14Addr = (unsigned long)irq14; 
	IDT[46].offset_lowerbits = irq14Addr & 0xffff;
	IDT[46].selector = 0x08;
	IDT[46].zero = 0;
	IDT[46].type_attr = 0x8e;
	IDT[46].offset_higherbits = (irq14Addr & 0xffff0000) >> 16;
 
        unsigned long irq15Addr = (unsigned long)irq15; 
	IDT[47].offset_lowerbits = irq15Addr & 0xffff;
	IDT[47].selector = 0x08;
	IDT[47].zero = 0;
	IDT[47].type_attr = 0x8e;
	IDT[47].offset_higherbits = (irq15Addr & 0xffff0000) >> 16;
}

void interrupt_set_eoi(void)
	{ system_outb(0x20, 0x20); };

void interrupt_set_handler(int irqId, void(*handleFunction)(void))
{
	interrupt_handlers[irqId] = handleFunction;
}

void init_idt(void)
{
	init_interrupt_handlers();
 
	// remap the pic
	system_outb(0x20, 0x11);
        system_outb(0xA0, 0x11);
        system_outb(0x21, 0x20);
        system_outb(0xA1, 40);
        system_outb(0x21, 0x04);
        system_outb(0xA1, 0x02);
        system_outb(0x21, 0x01);
        system_outb(0xA1, 0x01);
        system_outb(0x21, 0x0);
        system_outb(0xA1, 0x0);

	idt_fill();

	// move c idt struct and data to a struct taht the cpu likes
	unsigned long idtAddr = (unsigned long)IDT;
	signed long idt_ptr[2];
	idt_ptr[0] = (sizeof (struct IDT_entry) * 256) + ((idtAddr & 0xffff) << 16);
	idt_ptr[1] = idtAddr >> 16 ;
 
        extern int load_idt();
	load_idt(idt_ptr);
}

extern void irq0_handler(void)
{
	interrupt_set_eoi();
	(*(interrupt_handlers[0]))();
}
extern void irq1_handler(void)
{
	interrupt_set_eoi();
	(*(interrupt_handlers[1]))();
}
extern void irq2_handler(void)
{
	interrupt_set_eoi();
	(*(interrupt_handlers[2]))();
}
extern void irq3_handler(void)
{
	interrupt_set_eoi();
	(*(interrupt_handlers[3]))();
}
extern void irq4_handler(void)
{
	interrupt_set_eoi();
	(*(interrupt_handlers[4]))();
}
extern void irq5_handler(void)
{
	interrupt_set_eoi();
	(*(interrupt_handlers[5]))();
}
extern void irq6_handler(void)
{
	interrupt_set_eoi();
	(*(interrupt_handlers[6]))();
}
extern void irq7_handler(void)
{
	interrupt_set_eoi();
	(*(interrupt_handlers[7]))();
}
extern void irq8_handler(void)
{
	system_outb(0xA0, 0x20);
	interrupt_set_eoi();
}
extern void irq9_handler(void)
{
	system_outb(0xA0, 0x20);
	interrupt_set_eoi();
}
extern void irq10_handler(void)
{
	system_outb(0xA0, 0x20);
	interrupt_set_eoi();
}
extern void irq11_handler(void)
{
	system_outb(0xA0, 0x20);
	interrupt_set_eoi();
}
extern void irq12_handler(void)
{
	  system_outb(0xA0, 0x20);
	interrupt_set_eoi();
}
extern void irq13_handler(void)
{
	system_outb(0xA0, 0x20);
	interrupt_set_eoi();
}
extern void irq14_handler(void)
{
	system_outb(0xA0, 0x20);
	interrupt_set_eoi();
}
extern void irq15_handler(void)
{
	system_outb(0xA0, 0x20);
	interrupt_set_eoi();
}
