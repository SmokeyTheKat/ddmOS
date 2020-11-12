#ifndef __ddmos_ddsh_h__
#define __ddmos_ddsh_h__

#include "./tty.h"
#include "./system.h"
#include "./keyboard.h"
#include "./kernel.h"


void init_ddsh(void);
void ddsh_interrupt(void);
char* ddsh_history_get(int d);
void ddsh_interrupt_key(uint8t key);





#endif
