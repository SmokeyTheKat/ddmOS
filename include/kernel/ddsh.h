#ifndef __ddmos_ddsh_h__
#define __ddmos_ddsh_h__

#include "./tty.h"
#include "./system.h"
#include "./keyboard.h"
#include "./kernel.h"


void init_ddsh(void);
void ddsh_interrupt(char* _v);
char* ddsh_history_get(int d);





#endif
