#ifndef __DDMOS_BEEP_H__
#define __DDMOS_BEEP_H__

#include <ddcLib/ddcDef.h>

void pcspk_play(uint32t freq);
void pcspk_nosound(void);
void pcspk_beep(uint32t freq, uint32t time);

#endif
