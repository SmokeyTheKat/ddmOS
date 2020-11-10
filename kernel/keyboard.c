#include "../include/kernel/keyboard.h"
#include "../include/ddcLib/ddcString.h"

static bool shiftd = false;
static void (*keyboardFocusFunc)(uint8t) = ddsh_interrupt_key;
static bool keyboardFocusIsRaw = false;

void init_keyboard(void)
{
	system_outb(0x21, 0xFD);
	interrupt_set_handler(1, keyboard_interrupt_handler);
}

void keyboard_set_focus(void(*focusFunc)(uint8t), bool isRawInput)
{
	keyboardFocusFunc = focusFunc;
	keyboardFocusIsRaw = isRawInput;
}

void keyboard_interrupt_handler(void)
{
	if (keyboardFocusIsRaw) (*keyboardFocusFunc)(system_inb(KB_DATA_PORT));
	uint8t key = system_inb(KB_DATA_PORT);

	switch (key)
	{
		case 0x2A:
			shiftd = true;
			break;
		case 0xAA:
			shiftd = false;
			break;
		case KEY_ENTER:
			(*keyboardFocusFunc)('\n');
			break;
		case KEY_BACKSPACE:
			(*keyboardFocusFunc)('\b');
			break;
		case KEY_TAB:
			for (int i = 0; i < 4; i++)
				(*keyboardFocusFunc)(' ');
			break;
			
		default:
			if (key < 128)
			{
				if (shiftd)
					(*keyboardFocusFunc)(keyboard_ascii_to_char_shift(key));
				else
					(*keyboardFocusFunc)(keyboard_ascii_to_char(key));
			}
			break;
	}
}

char keyboard_ascii_to_char(uint8t keyCode)
{
	switch (keyCode)
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
char keyboard_ascii_to_char_shift(uint8t keyCode)
{
	switch (keyCode)
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
