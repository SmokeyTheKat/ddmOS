#include "../include/kernel/ddsh.h"
#include "../include/kernel/keyboard.h"
#include "../include/ddcLib/ddcString.h"
#include "../include/ddcLib/ddcMem.h"
#include "../usr/include/bf.h"

static ddString buffer;
static int bufferPos = -1;

void init_ddsh(void)
{
	buffer = make_multi_ddString_cstring("\0", 200);
}
static void buffer_clear(void)
{
	for (sizet i = 0; i < buffer.length; i++)
	{
		buffer.cstr[i] = '\0';
	}
	buffer.length = 0;
	bufferPos = -1;
}

static void rewrite_line(void)
{
	int popXPos = g_selectedTerm.cursorPos.x;
	int popYPos = g_selectedTerm.cursorPos.y;
	ddtty_delete_line(&g_selectedTerm);
	ddtty_cursor_move_to(&g_selectedTerm, 0, g_selectedTerm.cursorPos.y);
	kernel_ps1(&g_selectedTerm);
	ddtty_write_cstring(&g_selectedTerm, buffer.cstr);
	ddtty_cursor_move_to(&g_selectedTerm, popXPos, popYPos);
}

void ddsh_interrupt_key(uint8t key)
{
	if (key == 234)
	{
		return;
	}
	if (key == 235)
	{
		return;
	}
	if (key == 232)
	{
		if (bufferPos < 0) return;
		bufferPos--;
		ddtty_cursor_move(&g_selectedTerm, -1, 0);
		return;
	}
	if (key == 233)
	{
		if ((ddsize)(bufferPos + 1) >= buffer.length) return;
		ddtty_cursor_move(&g_selectedTerm, 1, 0);
		bufferPos++;
		return;
	}
	if (key == '\b')
	{
		if (bufferPos == -1) return;
		ddString_delete_at(&buffer, bufferPos);
		ddtty_write_char(&g_selectedTerm, key);
		rewrite_line();
		bufferPos--;
		return;
	}
	if (key == '\n')
	{
		ddtty_write_char(&g_selectedTerm, '\n');
		ddsh_interrupt();
		buffer_clear();
		return;
	}
	ddString_insert_char_at(&buffer, key, bufferPos+1);
	ddtty_cursor_move(&g_selectedTerm, 1, 0);
	rewrite_line();
	bufferPos++;
}

void ddsh_interrupt()
{
	if (ddString_compare(buffer, make_constant_ddString("PRINT")))
	{
		ddtty_write_cstring(&g_selectedTerm, "OGMGOOG");
		ddtty_write_char(&g_selectedTerm, '\n');
	}
	if (ddString_compare(buffer, make_constant_ddString("CLEAR")))
	{
		ddtty_clear(&g_selectedTerm);
	}
	if (ddString_compare(buffer, make_constant_ddString("POP")))
	{
		ddtty_pop_top(&g_selectedTerm);
	}
	if (ddString_compare(buffer, make_constant_ddString("POWEROFF")))
	{
		ddtty_write_cstring(&g_selectedTerm, "SHUTTING DOWN...");
		system_outd(0xB004, 0x2000);
		ddtty_write_char(&g_selectedTerm, '\n');
	}
	if (ddString_compare(buffer, make_constant_ddString("REBOOT")))
	{
		ddtty_write_cstring(&g_selectedTerm, "REBOOTING...");
		system_reboot();
		ddtty_write_char(&g_selectedTerm, '\n');
	}
	if (ddString_compare(buffer, make_constant_ddString("SMOKEY ITS DINNER TIME")))
	{
		ddtty_write_cstring(&g_selectedTerm, "MEOW! MEOW! MEOW! IM HUNGURY!");
		ddtty_write_char(&g_selectedTerm, '\n');
	}
	if (buffer.cstr[0] == 'B' && buffer.cstr[1] == 'F' && buffer.cstr[2] == ':')
	{
		bf_compute(buffer.cstr);
		ddtty_write_char(&g_selectedTerm, '\n');
	}
	kernel_ps1(&g_selectedTerm);
}
