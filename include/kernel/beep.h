#ifndef __ddmos_beep_h__
#define __ddmos_beep_h__

#include "./system.h"

void system_beep(uint32t frequency);
void system_cbeep(uint32t frequency, double length);
void system_nobeep(void);

#endif
