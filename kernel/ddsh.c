#include "../include/kernel/ddsh.h"
#include "../include/kernel/keyboard.h"
#include "../include/ddcLib/ddcString.h"
#include "../include/ddcLib/ddcMem.h"
#include "../usr/include/bf.h"

void init_ddsh(void)
{
}

void ddsh_interrupt_key(uint8t key)
{
	if (key == '\n')
	{
		char line[g_mainTerm.textSize.x+1];
		ddMem_copy_offset_step(line, g_mainTerm.textBuffer, 0, 
				(g_mainTerm.cursorPos.y*g_mainTerm.textSize.x*3)+(9*3),
				3, g_mainTerm.textSize.x*3);
		//line[g_mainTerm.textSize.x] = '\0';
		ddtty_write_char(&g_mainTerm, '\n');
		ddtty_write_cstring(&g_mainTerm, line);
		return;
	}
	ddtty_write_char(&g_mainTerm, key);
}

/*
void ddsh_interrupt(char* _v)
{
	hisPos = -1;
	sizet _lv = 0;
	for (; _v[_lv] != '\0'; _lv++);
	if (_lv <= 0) { kernel_ps1(&g_mainTerm); return; };
	if (ddsh_compare("PRINT", _v, 5, _lv))
	{
		ddtty_write_cstring(&g_mainTerm, "OGMGOOG");
		ddtty_write_char(&g_mainTerm, '\n');
	}
	if (ddsh_compare("CLEAR", _v, 5, _lv))
	{
		ddtty_clear(&g_mainTerm);
	}
	if (ddsh_compare("POP", _v, 3, _lv))
	{
		ddtty_pop_top(&g_mainTerm);
	}
	if (ddsh_compare("POWEROFF", _v, 8, _lv))
	{
		ddtty_write_cstring(&g_mainTerm, "SHUTTING DOWN...");
		system_outd(0xB004, 0x2000);
		ddtty_write_char(&g_mainTerm, '\n');
	}
	if (ddsh_compare("REBOOT", _v, 6, _lv))
	{
		ddtty_write_cstring(&g_mainTerm, "REBOOTING...");
		system_reboot();
		ddtty_write_char(&g_mainTerm, '\n');
	}
	if (ddsh_compare("SMOKEY ITS DINNER TIME", _v, 22, _lv))
	{
		ddtty_write_cstring(&g_mainTerm, "MEOW! MEOW! MEOW! IM HUNGURY!");
		ddtty_write_char(&g_mainTerm, '\n');
	}
	if (ddsh_compare("BF:", _v, 3, 3))
	{
		bf_compute(_v);
		ddtty_write_char(&g_mainTerm, '\n');
	}
	ddsh_history_add(_v, _lv);
	kernel_ps1(&g_mainTerm);
}
*/
