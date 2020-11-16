#ifndef __ddmos_kernel_h__
#define __ddmos_kernel_h__

#include "./drivers/tty.h"
#include "../ddcDef.h"

extern struct ddtty g_selectedTerm;
extern struct ddtty g_kernelTerm1;
extern struct ddtty g_kernelTerm2;

extern void kmain(void);// kernel main function
void kernel_wait_io(uint32t _timerc);
void kernel_sleep(uint32t _timerc);
char kernel_get_input(void);
void kernel_test_input(void);
void kernel_ps1(struct ddtty* _dt);


#endif
