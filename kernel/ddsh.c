#include "../include/kernel/ddsh.h"
#include "../usr/include/bf.h"

char commHistory[5][100];

void init_ddsh(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			commHistory[i][j] = '\0';
		}
	}
}

//temp function yo
bool ddsh_compare(const char* _a, const char* _b, sizet _la, sizet _lb)
{
	if (_lb != _la) return false;
	for (sizet i = 0; i < _la; i++)
		if (_a[i] != _b[i]) return false;
	return true;
}
//another temproy func
void ddsh_copy(char* d, const char* s, sizet l)
{
	for (sizet i = 0; i < l; i++)
	{
		d[i] = s[i];
	}
}


void ddsh_history_add(const char* _v, sizet _l)
{
	for (int i = 3; i > 0; i--)
	{
		ddsh_copy(commHistory[i], commHistory[i-1], 100);
	}
	ddsh_copy(commHistory[0], _v, _l);
	commHistory[0][_l] = '\0';
}
int hisPos = -1;
char* ddsh_history_get(int d)
{
	if (hisPos + d < 0) { hisPos = -1; return "\0"; };
	if (hisPos + d > 3) return commHistory[3];
	hisPos += d;
	return commHistory[hisPos];
}


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
		system_outb(0xB004, 0x2000);
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
