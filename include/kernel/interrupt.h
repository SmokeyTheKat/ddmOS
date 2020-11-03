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

extern void keyboard_interrupt(void);

void init_idt();
extern void load_idt(uint32t*);




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






void irq0_handler(void);
void irq1_handler(void);
void irq2_handler(void);
void irq3_handler(void);
void irq4_handler(void);
void irq5_handler(void);
void irq6_handler(void);
void irq7_handler(void);
void irq8_handler(void);
void irq9_handler(void);
void irq10_handler(void);
void irq11_handler(void);
void irq12_handler(void);
void irq13_handler(void);
void irq14_handler(void);
void irq15_handler(void);







/*
void init_isrs(void);
extern void fault_handler(struct regs* _r);




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
*/



#endif
