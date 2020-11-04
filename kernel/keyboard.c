#include "../include/kernel/keyboard.h"

#define DDSH_BUFFER_SIZE 100
char term_ddsh_buffer[DDSH_BUFFER_SIZE];
int term_ddsh_buffer_pos;

void ddsh_buffer_clear(void)
{
	for (int i = 0; i < DDSH_BUFFER_SIZE; i++)
		term_ddsh_buffer[i] = '\0';
	term_ddsh_buffer_pos = 0;
}

void init_keyboard(void)
{
	system_outb(0x21, 0xFD);
	interrupt_set_handler(1, keyboard_interrupt_handler);
	ddsh_buffer_clear();
}

static bool shiftd = false;


void keyboard_interrupt_handler(void)
{
	char kc;

	system_outb(0x20, 0x20);//eoi

	uint8t status = system_inb(KB_STATUS_PORT);
	kc = system_inb(KB_DATA_PORT);

	if (!(status & 0x80))
	{
		if (kc == 42)
		{
			shiftd = true;
			return;
		}
	}
	if (kc & 0x80)
	{
		shiftd = false;
	}

	if (status & 0x01)
	{
		if (kc < 0) return;
		if (kc == KEY_RETURN)
		{
			term_write_char('\n');
			ddsh_interrupt(term_ddsh_buffer);
			ddsh_buffer_clear();
			return;
		}
		if (kc == KEY_RIGHT)
		{
			g_termColumn++;
			term_ddsh_buffer_pos++;
			term_update_cursor();
			return;
		}
		if (kc == KEY_LEFT)
		{
			if (term_ddsh_buffer_pos == 0) return;
			g_termColumn--;
			term_ddsh_buffer_pos--;
			term_update_cursor();
			return;
		}
		if (kc == KEY_BACKSPACE)
		{
			if (term_ddsh_buffer_pos == 0) return;
			g_termColumn--;
			term_write_char(' ');
			g_termColumn--;
			term_update_cursor();

			term_ddsh_buffer[term_ddsh_buffer_pos-1] = '\0';
			term_ddsh_buffer_pos--;
			return;
		}
		if (shiftd)
		{
			term_ddsh_buffer[term_ddsh_buffer_pos] = keyboard_ascii_to_char_shift(kc);
			term_ddsh_buffer_pos++;
			term_write_char(keyboard_ascii_to_char_shift(kc));
		}
		else
		{
			term_ddsh_buffer[term_ddsh_buffer_pos] = keyboard_ascii_to_char(kc);
			term_ddsh_buffer_pos++;
			term_write_char(keyboard_ascii_to_char(kc));
		}
	}
}

char keyboard_ascii_to_char(uint8t _kc)
{
	switch (_kc)
	{
		case KEY_A: return 'A';
		case KEY_B: return 'B';
		case KEY_C: return 'C';
		case KEY_D: return 'D';
		case KEY_E: return 'E';
		case KEY_F: return 'F';
		case KEY_G: return 'G';
		case KEY_H: return 'H';
		case KEY_I: return 'I';
		case KEY_J: return 'J';
		case KEY_K: return 'K';
		case KEY_L: return 'L';
		case KEY_M: return 'M';
		case KEY_N: return 'N';
		case KEY_O: return 'O';
		case KEY_P: return 'P';
		case KEY_Q: return 'Q';
		case KEY_R: return 'R';
		case KEY_S: return 'S';
		case KEY_T: return 'T';
		case KEY_U: return 'U';
		case KEY_V: return 'V';
		case KEY_W: return 'W';
		case KEY_X: return 'X';
		case KEY_Y: return 'Y';
		case KEY_Z: return 'Z';
		case KEY_DOT: return '.';
		case KEY_EQUAL: return '=';
		case KEY_MINUS: return '-';
		case KEY_FORESLHASH: return '/';
		case KEY_BACKSLASH: return '\\';
		case KEY_COMMA: return ',';
		case KEY_SPACE: return ' ';
		case KEY_SEMICOLON: return ';';
		case KEY_SQUARE_OPEN_BRACKET: return '[';
		case KEY_SQUARE_CLOSE_BRACKET: return ']';
		case KEY_0: return '0';
		case KEY_1: return '1';
		case KEY_2: return '2';
		case KEY_3: return '3';
		case KEY_4: return '4';
		case KEY_5: return '5';
		case KEY_6: return '6';
		case KEY_7: return '7';
		case KEY_8: return '8';
		case KEY_9: return '9';
		default: return 0;
	}
}
char keyboard_ascii_to_char_shift(uint8t _kc)
{
	switch (_kc)
	{
		case KEY_A: return 'A';
		case KEY_B: return 'B';
		case KEY_C: return 'C';
		case KEY_D: return 'D';
		case KEY_E: return 'E';
		case KEY_F: return 'F';
		case KEY_G: return 'G';
		case KEY_H: return 'H';
		case KEY_I: return 'I';
		case KEY_J: return 'J';
		case KEY_K: return 'K';
		case KEY_L: return 'L';
		case KEY_M: return 'M';
		case KEY_N: return 'N';
		case KEY_O: return 'O';
		case KEY_P: return 'P';
		case KEY_Q: return 'Q';
		case KEY_R: return 'R';
		case KEY_S: return 'S';
		case KEY_T: return 'T';
		case KEY_U: return 'U';
		case KEY_V: return 'V';
		case KEY_W: return 'W';
		case KEY_X: return 'X';
		case KEY_Y: return 'Y';
		case KEY_Z: return 'Z';
		case KEY_DOT: return '>';
		case KEY_EQUAL: return '+';
		case KEY_MINUS: return '_';
		case KEY_FORESLHASH: return '?';
		case KEY_BACKSLASH: return '|';
		case KEY_COMMA: return '<';
		case KEY_SPACE: return ' ';
		case KEY_SEMICOLON: return ':';
		case KEY_SQUARE_OPEN_BRACKET: return '{';
		case KEY_SQUARE_CLOSE_BRACKET: return '}';
		case KEY_0: return ')';
		case KEY_1: return '!';
		case KEY_2: return '@';
		case KEY_3: return '#';
		case KEY_4: return '$';
		case KEY_5: return '%';
		case KEY_6: return '^';
		case KEY_7: return '&';
		case KEY_8: return '*';
		case KEY_9: return '(';
		default: return 0;
	}
}
