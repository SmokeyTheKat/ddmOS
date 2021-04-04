#ifndef __DDMOS_VGA_H__
#define __DDMOS_VGA_H__

#include <ddcLib/ddcDef.h>

extern sizet g_term_y;
extern sizet g_term_x;
extern short g_term_color;
extern short* g_term_buffer;

typedef enum VColor VColor;
enum VColor
{
	VCOLOR_BLACK = 0x0000,
	VCOLOR_BLUE = 0x0100,
	VCOLOR_GREEN = 0x0200,
	VCOLOR_CYAN = 0x0300,
	VCOLOR_RED = 0x0400,
	VCOLOR_MAGENTA = 0x0500,
	VCOLOR_YELLOW = 0x0600,
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

sizet t_strlen(const char* _c);
void vga_set_color(VColor fg, VColor bg);
void vga_enable_cursor(void);
void vga_disable_cursor(void);
void vga_move_cursor(int x, int y);
void vga_update_cursor(void);
void vga_scroll_down(int n);
void init_vga(void);
void vga_write_char(char _c);
void vga_write(const char* _c, sizet _len);

#endif
