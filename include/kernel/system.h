#ifndef __DDMOS_SYSTEM_H__
#define __DDMOS_SYSTEM_H__

#include <ddcLib/ddcDef.h>

uint8t system_inb(uint16t _port);
void system_outb(uint16t _port, uint8t _v);
uint16t system_inw(uint32t _port);
void system_outw(uint32t _port, uint16t _v);
uint32t system_inl(uint64t _port);
void system_outl(uint64t _port, uint32t _v);
void system_await_input(void);
uint64t system_get_rdtsc(void);
void system_sleep(uint32t _t);
void system_sleep_seconds(double _t);
void system_halt(void);
void system_reboot(void);
void system_poweroff(void);
void* memset(void* _d, int8t _v, sizet _c);

struct regs
{
	uint16t gs, fs, es, ds;
	uint16t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint16t intNo, errorCode;
	uint16t eip, cs, eflags, useresp, ss;
};


#endif
