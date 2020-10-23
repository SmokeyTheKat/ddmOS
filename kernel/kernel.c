#include "../libs/ddcDef.h"
 
#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif
 
#if !defined(__i386__)
#error "compile with a ix86-elf compiler"
#endif

typedef enum vga_color vga_color;
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};
 
static inline uint8t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}
 
static inline uint16t vga_entry(unsigned char uc, uint8t color) 
{
	return (uint16t) uc | (uint16t) color << 8;
}
 
sizet strlen(const char* str) 
{
	sizet len = 0;
	while (str[len])
		len++;
	return len;
}
 
static const sizet VGA_WIDTH = 80;
static const sizet VGA_HEIGHT = 25;
 
sizet terminal_row;
sizet terminal_column;
uint8t terminal_color;
uint16t* terminal_buffer;
 
void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16t*) 0xB8000;
	for (sizet y = 0; y < VGA_HEIGHT; y++) {
		for (sizet x = 0; x < VGA_WIDTH; x++) {
			const sizet index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8t color) 
{
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8t color, sizet x, sizet y) 
{
	const sizet index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) 
{
	if (c == '\n')
	{
		terminal_column=0;
		terminal_row++;
	}
	else
	{
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (++terminal_column == VGA_WIDTH) {
			terminal_column = 0;
			if (++terminal_row == VGA_HEIGHT)
				terminal_row = 0;
		}
	}
}
 
void terminal_write(const char* data, sizet size) 
{
	for (sizet i = 0; i < size; i++)
	{
		terminal_putchar(data[i]);
	}
}
 
void terminal_writestring(const char* data) 
{
	terminal_write(data, strlen(data));
}
 
void kernel_main(void) 
{
	terminal_initialize();
 
	terminal_color = VGA_COLOR_WHITE;
	terminal_writestring("Hello, YOYOYOYOYOYOY!\n");
	terminal_color = VGA_COLOR_RED;
	terminal_writestring("what is going on gamers yo\n\n\n");
	terminal_color = VGA_COLOR_BLUE;
	terminal_writestring("hi!\n");
}
