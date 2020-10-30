#include "../include/kernel/gdt.h"

struct gdtEntry gdt[3];
struct gdtPtr gdtp;


void gdt_set_gate(int _v, uint32t _b, uint32t _l, uint8t _a, uint8t _g)
{
	gdt[_v].lowBase = _b & 0xFFFF;
	gdt[_v].midBase = (_b >> 16) & 0xFF;
	gdt[_v].highBase = (_b >> 24) & 0xFF;

	gdt[_v].lowLimit = _l & 0xFFFF;
	gdt[_v].granu = (_l >> 16) & 0xF;

	gdt[_v].granu |= _g & 0xF0;
	gdt[_v].access = _a;
}

void init_gdt(void)
{
	gdtp.limit = (sizeof(struct gdtEntry) * 3) - 1;
	gdtp.base = (uint16t)&gdt;

	gdt_set_gate(0,0,0,0,0);
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	gdt_flush((void*)&gdtp);
}
