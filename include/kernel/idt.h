#ifndef __DDMOS_IDT_H__
#define __DDMOS_IDT_H__

#include <ddcLib/ddcDef.h>

void init_idt(void);
void idt_set_isr(int isr, void(*fun)(void));

struct IDT64
{
	uint16t offset_low;
	uint16t selector;
	uint8t ist;
	uint8t types_attr;
	uint16t offset_mid;
	uint32t offset_high;
	uint32t zero;
};

#endif
