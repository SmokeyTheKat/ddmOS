#ifndef __ddmos_kernel_h__
#define __ddmos_kernel_h__

#include "../ddcDef.h"
#include "tty.h"
#include "keyboard.h"
#include "system.h"

extern void kmain();// kernel main function
uint8t kernel_inb(uint16t _port);
void kernel_outb(uint16t _port, uint8t _v);
void kernel_wait_io(uint32t _timerc);
void kernel_sleep(uint32t _timerc);
char kernel_get_input(void);
void kernel_test_input(void);


#endif
