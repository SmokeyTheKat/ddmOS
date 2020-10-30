#ifndef __ddmos_gdt_h__
#define __ddmos_gdt_h__

#include "../ddcDef.h"

struct gdtEntry
{
	uint16t lowLimit;	
	uint16t lowBase;	
	uint8t midBase;	
	uint8t access;	
	uint8t granu;	
	uint8t highBase;	
}__attribute__((packed));
struct gdtPtr
{
	uint16t limit;
	uint16t base;
}__attribute__((packed));


extern void gdt_flush(void*);
void gdt_set_gate(int _v, uint32t _b, uint32t _l, uint8t _a, uint8t _g);
void init_gdt(void);



#endif
