#ifndef __ddmos_tty_h__
#define __ddmos_tty_h__ 1

#include "../../ddcDef.h"
#include "../sys/system.h"

extern sizet g_termYPos;// current pos of cursor y
extern sizet g_termXPos;// current pos of cursor x
extern short g_termColor;// current terminal color
extern short* g_termBuffer;// pointer to vga video memory

typedef enum VColor VColor;
enum VColor{
	VCOLOR_BLACK = 0x0000,
	VCOLOR_BLUE = 0x0100,
	VCOLOR_GREEN = 0x0200,
	VCOLOR_CYAN = 0x0300,
	VCOLOR_RED = 0x0400,
	VCOLOR_MAGENTA = 0x0500,
	VCOLOR_BROWN = 0x0600,
	VCOLOR_LIGHT_GREY = 0x0700,
	VCOLOR_DARK_GREY = 0x0800,
	VCOLOR_LIGHT_BLUE = 0x0900,
	VCOLOR_LIGHT_GREEN = 0x0A00,
	VCOLOR_LIGHT_CYAN = 0x0B00,
	VCOLOR_LIGHT_RED = 0x0C00,
	VCOLOR_LIGHT_MAGENTA = 0x0D00,
	VCOLOR_LIGHT_BROWN = 0x0E00,
	VCOLOR_WHITE = 0x0F00
};


sizet t_strlen(const char* _c);// temporary strlen func
void term_set_color(VColor fg, VColor bg);
void term_enable_cursor(uint8t cs, uint8t ce);
//void term_enable_cursor(void);
void term_disable_cursor(void);
void term_move_cursor(int x, int y);
void term_update_cursor(void);
void term_clear(void);
void init_term(void);// initializes terminal
void term_write_char(char _c);// prints char 
void term_write(const char* _c, sizet _len);// writes char string
void term_write_cstring(const char* _c);// gets leng of cstring then writes it
void term_pop_top(void);
void term_delete_line(void);


#endif
