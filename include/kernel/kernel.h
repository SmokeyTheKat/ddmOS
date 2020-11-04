#ifndef __ddmos_kernel_h__
#define __ddmos_kernel_h__

#include "../ddcDef.h"

extern void kmain(void);// kernel main function
void kernel_wait_io(uint32t _timerc);
void kernel_sleep(uint32t _timerc);
char kernel_get_input(void);
void kernel_test_input(void);
void kernel_ps1(void);


#endif
