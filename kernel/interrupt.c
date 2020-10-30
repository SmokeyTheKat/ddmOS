#include "../include/kernel/interrupt.h"

static struct idtEntry idt[IDT_SIZE];
static struct idtPtr idtp;


void idt_set_gate(uint8t _v, uint32t _b, uint16t _s, uint8t _f)
{
	//routines address
	idt[_v].lBase = _b & 0xFFFF;
	idt[_v].hBase = (_b >> 16) & 0xFFFF;

	//segment and flags yo
	idt[_v].selector = _s;
	idt[_v].zero = 0;
	idt[_v].flags = _f;
}
void init_idt(void)
{
	idtp.limit = (sizeof(struct idtEntry) * IDT_SIZE) - 1;
	idtp.base = &idt;
	memset(&idt, 0, sizeof(struct idtEntry) * IDT_SIZE);
	idt_load(&idtp);
}

static void* irq_routines[16] = {
	null, null, null, null, null, null, null, null,
	null, null, null, null, null, null, null, null
};

void irq_add_handler(int _irq, void(*_h)(struct regs* _r))
{
	irq_routines[_irq] = _h;
}
void irq_remove_handler(int _irq)
{
	irq_routines[_irq] = null;
}
void irq_remap(void)
{
	system_outb(0x20, 0x11);
	system_outb(0xA0, 0x11);

	system_outb(0x21, 0x20);
	system_outb(0xA1, 0x28);

	system_outb(0x21, 0x04);
	system_outb(0xA1, 0x02);

	system_outb(0x21, 0x01);
	system_outb(0xA1, 0x01);

	system_outb(0x21, 0x0);
	system_outb(0xA1, 0x0);
}

void init_irq(void)
{
	irq_remap();

	idt_set_gate(32, (uint16t)irq0, 0x08, 0x8E);
	idt_set_gate(33, (uint16t)irq1, 0x08, 0x8E);
	idt_set_gate(34, (uint16t)irq2, 0x08, 0x8E);
	idt_set_gate(35, (uint16t)irq3, 0x08, 0x8E);
	idt_set_gate(36, (uint16t)irq4, 0x08, 0x8E);
	idt_set_gate(37, (uint16t)irq5, 0x08, 0x8E);
	idt_set_gate(38, (uint16t)irq6, 0x08, 0x8E);
	idt_set_gate(39, (uint16t)irq7, 0x08, 0x8E);

	idt_set_gate(40, (uint16t)irq8, 0x08, 0x8E);
	idt_set_gate(41, (uint16t)irq9, 0x08, 0x8E);
	idt_set_gate(42, (uint16t)irq10, 0x08, 0x8E);
	idt_set_gate(43, (uint16t)irq11, 0x08, 0x8E);
	idt_set_gate(44, (uint16t)irq12, 0x08, 0x8E);
	idt_set_gate(45, (uint16t)irq13, 0x08, 0x8E);
	idt_set_gate(46, (uint16t)irq14, 0x08, 0x8E);
	idt_set_gate(47, (uint16t)irq15, 0x08, 0x8E);
}

extern void irq_handler(struct regs* _r)
{
	void (*_h)(struct regs* _r);

	_h = irq_routines[_r->intNo - 32];
	if (_h) _h(_r);
	if (_r->intNo >= 40) system_outb(0xA0, 0x20);//eoi
	system_outb(0x20, 0x20);//eoi
}







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
