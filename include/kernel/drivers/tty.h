#ifndef __ddmos_tty_h__
#define __ddmos_tty_h__

#include "../../ddcLib/ddcVec.h"
#include "./vga.h"
#include "../sys/fonts.h"
#include "../../ddcLib/ddcMake.h"
#include "../../ddcLib/ddcString.h"
#include "../../ddcLib/ddcMem.h"

struct ddtty
{
	ddIVec2 	cursorPos;
	uint8t		cursorColor;
	uint8t		cursorBGColor;
	bool		cursorVisible;
	uint8t		fgColor;
	uint8t		bgColor;
	ddIVec2 	textSize;
	ddIVec2		position;
	ddIVec2		size;
	char*	  	textBuffer;
};


struct ddtty make_ddtty(ddIVec2 _pos, ddIVec2 _size, ddIVec2 _ts, uint8t _fgc, uint8t _bgc);
void raze_ddtty(struct ddtty* _dt);
void ddtty_set_color(struct ddtty* _dt, uint8t _fgc, uint8t _bgc);
void ddtty_cursor_enable(struct ddtty* _dt);
void ddtty_cursor_disable(struct ddtty* _dt);
void ddtty_cursor_update(struct ddtty* _dt);
void ddtty_cursor_move(struct ddtty* _dt, int x, int y);
void ddtty_cursor_move_to(struct ddtty* _dt, int x, int y);
void ddtty_draw_cursor(struct ddtty* _dt);
void ddtty_undraw_cursor(struct ddtty* _dt);
void ddtty_clear(struct ddtty* _dt);
void ddtty_pop_top(struct ddtty* _dt);
void ddtty_pop_bottom(struct ddtty* _dt);
void ddtty_write_char(struct ddtty* _dt, char _c);
void ddtty_write_cstring(struct ddtty* _dt, const char* _c);
void ddtty_write(struct ddtty* _dt, const char* _cs, sizet _len);
void ddtty_redraw(struct ddtty* _dt);
void ddtty_redraw_line(struct ddtty* _dt, uint16t _li);
void ddtty_delete_line(struct ddtty* _dt);



#endif
