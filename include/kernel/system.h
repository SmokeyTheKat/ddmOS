#ifndef __ddmos_system_h__
#define __ddmos_system_h__

#include "../ddcDef.h"


uint8t system_inb(uint16t port);
uint16t system_inw(uint16t port);
uint32t system_ind(uint16t port);
void system_outb(uint16t port, uint8t value);
void system_outw(uint16t port, int16t value);
void system_outd(uint16t port, uint32t value);
void system_halt(void);

void system_await_input(void);
uint64t system_get_rdtsc(void);
void system_sleep(uint32t sleepTime);
void system_reboot(void);
//void system_set_vga_mode(uint8t _move);

//get rid of this yo
void* memset(void* _d, int8t _v, sizet _c);

struct regs
{
	uint16t gs, fs, es, ds;
	uint16t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint16t intNo, errorCode;
	uint16t eip, cs, eflags, useresp, ss;
};


#endif
