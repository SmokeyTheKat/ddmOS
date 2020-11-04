#include "../include/kernel/ddsh.h"

bool ddsh_compare(const char* _a, const char* _b, sizet _la, sizet _lb)
{
	if (_lb != _la) return false;
	for (sizet i = 0; i < _la; i++)
		if (_a[i] != _b[i]) return false;
	return true;
}


void ddsh_interrupt(char* _v)
{
	sizet _lv = 0;
	for (; _v[_lv] != '\0'; _lv++);
	if (ddsh_compare("PRINT", _v, 5, _lv))
	{
		term_write_cstring("OGMGOOG");
		term_write_char('\n');
	}
	if (ddsh_compare("POWEROFF", _v, 8, _lv))
	{
		term_write_cstring("SHUTTING DOWN...");
		system_outb(0xB004, 0x2000);
		term_write_char('\n');
	}
	if (ddsh_compare("REBOOT", _v, 6, _lv))
	{
		term_write_cstring("REBOOTING...");
		system_reboot();
		term_write_char('\n');
	}
	if (ddsh_compare("SMOKEY ITS DINNER TIME", _v, 22, _lv))
	{
		term_write_cstring("MEOW! MEOW! MEOW! IM HUNGURY!");
		term_write_char('\n');
	}
	kernel_ps1();
}
