#ifndef __ddmos_interrupt_h__
#define __ddmos_interrupt_h__

#include "../../ddcDef.h"
#include "../sys/system.h"
#include "../io/keyboard.h"
#include "../drivers/tty.h"

#define IDT_SIZE 256

struct IDT_entry{
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
};

void init_idt(void);
void interrupt_set_handler(int irqId, void(*handleFunction)(void));
void interrupt_set_eoi(void);

extern void irq0_handler(void);
extern void irq1_handler(void);
extern void irq2_handler(void);
extern void irq3_handler(void);
extern void irq4_handler(void);
extern void irq5_handler(void);
extern void irq6_handler(void);
extern void irq7_handler(void);
extern void irq8_handler(void);
extern void irq9_handler(void);
extern void irq10_handler(void);
extern void irq11_handler(void);
extern void irq12_handler(void);
extern void irq13_handler(void);
extern void irq14_handler(void);
extern void irq15_handler(void);

#endif
