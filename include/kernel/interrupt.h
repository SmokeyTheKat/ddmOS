#ifndef __ddmos_interrupt_h__
#define __ddmos_interrupt_h__

#include "../ddcDef.h"
#include "system.h"
#include "keyboard.h"

#define IDT_SIZE 256

struct idtEntry
{
	uint16t lBase;
	uint16t hBase;
	uint16t selector;
	uint8t zero;
	uint8t flags;
}__attribute__((packed));
struct idtPtr
{
	uint16t limit;
	uint16t base;
}__attribute__((packed));

extern void keyboard_interrupt(void);

void idt_set_gate(uint8t _v, uint32t _b, uint16t _s, uint8t _f);
void init_idt(void);
extern void idt_load(uint32t* idtPtr);

void irq_add_handler(int _irq, void(*_h)(struct regs* _r));
void irq_remove_handler(int _irq);
void irq_remap(void);
void init_irq(void);
extern void irq_handler(struct regs* _r);

void init_isrs(void);
extern void fault_handler(struct regs* _r);

extern void irq0(void);
extern void irq1(void);
extern void irq2(void);
extern void irq3(void);
extern void irq4(void);
extern void irq5(void);
extern void irq6(void);
extern void irq7(void);
extern void irq8(void);
extern void irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);

extern void isr0(void);
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);




#endif
