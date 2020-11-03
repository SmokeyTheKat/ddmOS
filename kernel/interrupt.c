#include "../include/kernel/interrupt.h"

static struct idtEntry idt[IDT_SIZE];


void init_idt(void)
{
	uint32t irq0Addr;
	uint32t irq1Addr;
	uint32t irq2Addr;
	uint32t irq3Addr;
	uint32t irq4Addr;
	uint32t irq5Addr;
	uint32t irq6Addr;
	uint32t irq7Addr;
	uint32t irq8Addr;
	uint32t irq9Addr;
	uint32t irq10Addr;
	uint32t irq11Addr;
	uint32t irq12Addr;
	uint32t irq13Addr;
	uint32t irq14Addr;
	uint32t irq15Addr;
	uint32t idtAddr;
	uint32t idtPtr[2];


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

	irq0Addr = (uint16t)irq0;
	idt[32].lBase = irq0Addr & 0xffff;
	idt[32].selector = 0x08;
	idt[32].zero = 0;
	idt[32].flags = (irq0Addr & 0xffff0000) >> 16;
	irq1Addr = (uint16t)irq1;
	idt[33].lBase = irq1Addr & 0xffff;
	idt[33].selector = 0x08;
	idt[33].zero = 0;
	idt[33].flags = (irq1Addr & 0xffff0000) >> 16;
	irq2Addr = (uint16t)irq2;
	idt[34].lBase = irq2Addr & 0xffff;
	idt[34].selector = 0x08;
	idt[34].zero = 0;
	idt[34].flags = (irq2Addr & 0xffff0000) >> 16;
	irq3Addr = (uint16t)irq3;
	idt[35].lBase = irq3Addr & 0xffff;
	idt[35].selector = 0x08;
	idt[35].zero = 0;
	idt[35].flags = (irq3Addr & 0xffff0000) >> 16;
	irq4Addr = (uint16t)irq4;
	idt[36].lBase = irq4Addr & 0xffff;
	idt[36].selector = 0x08;
	idt[36].zero = 0;
	idt[36].flags = (irq4Addr & 0xffff0000) >> 16;
	irq5Addr = (uint16t)irq5;
	idt[37].lBase = irq5Addr & 0xffff;
	idt[37].selector = 0x08;
	idt[37].zero = 0;
	idt[37].flags = (irq5Addr & 0xffff0000) >> 16;
	irq6Addr = (uint16t)irq6;
	idt[38].lBase = irq6Addr & 0xffff;
	idt[38].selector = 0x08;
	idt[38].zero = 0;
	idt[38].flags = (irq6Addr & 0xffff0000) >> 16;
	irq7Addr = (uint16t)irq7;
	idt[39].lBase = irq7Addr & 0xffff;
	idt[39].selector = 0x08;
	idt[39].zero = 0;
	idt[39].flags = (irq7Addr & 0xffff0000) >> 16;
	irq8Addr = (uint16t)irq8;
	idt[40].lBase = irq8Addr & 0xffff;
	idt[40].selector = 0x08;
	idt[40].zero = 0;
	idt[40].flags = (irq8Addr & 0xffff0000) >> 16;
	irq9Addr = (uint16t)irq9;
	idt[41].lBase = irq9Addr & 0xffff;
	idt[41].selector = 0x08;
	idt[41].zero = 0;
	idt[41].flags = (irq9Addr & 0xffff0000) >> 16;
	irq10Addr = (uint16t)irq10;
	idt[42].lBase = irq10Addr & 0xffff;
	idt[42].selector = 0x08;
	idt[42].zero = 0;
	idt[42].flags = (irq10Addr & 0xffff0000) >> 16;
	irq11Addr = (uint16t)irq11;
	idt[43].lBase = irq11Addr & 0xffff;
	idt[43].selector = 0x08;
	idt[43].zero = 0;
	idt[43].flags = (irq11Addr & 0xffff0000) >> 16;
	irq12Addr = (uint16t)irq12;
	idt[44].lBase = irq12Addr & 0xffff;
	idt[44].selector = 0x08;
	idt[44].zero = 0;
	idt[44].flags = (irq12Addr & 0xffff0000) >> 16;
	irq13Addr = (uint16t)irq13;
	idt[45].lBase = irq13Addr & 0xffff;
	idt[45].selector = 0x08;
	idt[45].zero = 0;
	idt[45].flags = (irq13Addr & 0xffff0000) >> 16;
	irq14Addr = (uint16t)irq14;
	idt[46].lBase = irq14Addr & 0xffff;
	idt[46].selector = 0x08;
	idt[46].zero = 0;
	idt[46].flags = (irq14Addr & 0xffff0000) >> 16;
	irq15Addr = (uint16t)irq15;
	idt[47].lBase = irq15Addr & 0xffff;
	idt[47].selector = 0x08;
	idt[47].zero = 0;
	idt[47].flags = (irq15Addr & 0xffff0000) >> 16;



	idtAddr = (uint32t)idt;
	idtPtr[0] = (sizeof(struct idtEntry) * IDT_SIZE) + ((idtAddr & 0xffff) << 16);
	idtPtr[1] = idtAddr >> 16;

	load_idt(idtPtr);

}




void irq0_handler(void)
{
	system_outb(0x20, 0x20);//eoi
}
void irq1_handler(void)
{
	system_outb(0x20, 0x20);//eoi
	term_write_cstring("omgogmogmogmgomg");
}
void irq2_handler(void)
{
	system_outb(0x20, 0x20);//eoi
}
void irq3_handler(void)
{
	system_outb(0x20, 0x20);//eoi
}
void irq4_handler(void)
{
	system_outb(0x20, 0x20);//eoi
}
void irq5_handler(void)
{
	system_outb(0x20, 0x20);//eoi
}
void irq6_handler(void)
{
	system_outb(0x20, 0x20);//eoi
}
void irq7_handler(void)
{
	system_outb(0x20, 0x20);//eoi
}
void irq8_handler(void)
{
	system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}
void irq9_handler(void)
{
	system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}
void irq10_handler(void)
{
	system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}
void irq11_handler(void)
{
	system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}
void irq12_handler(void)
{
	system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}
void irq13_handler(void)
{
	system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}
void irq14_handler(void)
{
	system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}
void irq15_handler(void)
{
	system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}








/*



void init_isrs(void)
{

	idt_set_gate(0, (uint16t)isr0, 0x08, 0x8E);
	idt_set_gate(1, (uint16t)isr1, 0x08, 0x8E);
	idt_set_gate(2, (uint16t)isr2, 0x08, 0x8E);
	idt_set_gate(3, (uint16t)isr3, 0x08, 0x8E);
	idt_set_gate(4, (uint16t)isr4, 0x08, 0x8E);
	idt_set_gate(5, (uint16t)isr5, 0x08, 0x8E);
	idt_set_gate(6, (uint16t)isr6, 0x08, 0x8E);
	idt_set_gate(7, (uint16t)isr7, 0x08, 0x8E);

	idt_set_gate(8, (uint16t)isr8, 0x08, 0x8E);
	idt_set_gate(9, (uint16t)isr9, 0x08, 0x8E);
	idt_set_gate(10, (uint16t)isr10, 0x08, 0x8E);
	idt_set_gate(11, (uint16t)isr11, 0x08, 0x8E);
	idt_set_gate(12, (uint16t)isr12, 0x08, 0x8E);
	idt_set_gate(13, (uint16t)isr13, 0x08, 0x8E);
	idt_set_gate(14, (uint16t)isr14, 0x08, 0x8E);
	idt_set_gate(15, (uint16t)isr15, 0x08, 0x8E);

	idt_set_gate(16, (uint16t)isr16, 0x08, 0x8E);
	idt_set_gate(17, (uint16t)isr17, 0x08, 0x8E);
	idt_set_gate(18, (uint16t)isr18, 0x08, 0x8E);
	idt_set_gate(19, (uint16t)isr19, 0x08, 0x8E);
	idt_set_gate(20, (uint16t)isr20, 0x08, 0x8E);
	idt_set_gate(21, (uint16t)isr21, 0x08, 0x8E);
	idt_set_gate(22, (uint16t)isr22, 0x08, 0x8E);
	idt_set_gate(23, (uint16t)isr23, 0x08, 0x8E);

	idt_set_gate(24, (uint16t)isr24, 0x08, 0x8E);
	idt_set_gate(25, (uint16t)isr25, 0x08, 0x8E);
	idt_set_gate(26, (uint16t)isr26, 0x08, 0x8E);
	idt_set_gate(27, (uint16t)isr27, 0x08, 0x8E);
	idt_set_gate(28, (uint16t)isr28, 0x08, 0x8E);
	idt_set_gate(29, (uint16t)isr29, 0x08, 0x8E);
	idt_set_gate(30, (uint16t)isr30, 0x08, 0x8E);
	idt_set_gate(31, (uint16t)isr31, 0x08, 0x8E);
}
const char* exceptionMessages[] = {
	"Division by zero",
	"Debug",
	"Non maskable interrupt",
	"Breakpoint",
	"Into detected overflow",
	"Out of bounds",
	"Invalid opcode",
	"No coprocessor",

	"Double fault",
	"Coprocessor segment overrun",
	"Bad tss",
	"Segment not present",
	"Stack fault",
	"Unknown interrupt",
	"Coprocessor fault",

	"Alignment check",
	"Machine check",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",

	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved"
};

extern void fault_handler(struct regs* _r)
{
	if (_r->intNo < 32)
	{
		term_write_cstring(exceptionMessages[_r->intNo]);
		term_write_cstring(" Exception. Hault\n");
	}
}


*/
