#ifndef __ddmos_ddsh_h__
#define __ddmos_ddsh_h__

#include "../drivers/tty.h"
#include "../sys/system.h"
#include "../io/keyboard.h"
#include "../kernel.h"


void init_ddsh(void);
void ddsh_interrupt(void);
char* ddsh_history_get(int d);
void ddsh_interrupt_key(uint8t key);





#endif
