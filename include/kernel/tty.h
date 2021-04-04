#ifndef __DDMOS_TTY_H__
#define __DDMOS_TTY_H__

#include <kernel/keyboard.h>
#include <ddcLib/ddcDef.h>

struct vgatty
{
	int x, y;
	int width, height;
	int cx, cy;
};

void init_vgatty(void);
void vgatty_handle_key(uint8t key);

#endif
