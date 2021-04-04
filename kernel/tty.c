#include <kernel/tty.h>
#include <ddcLib/ddcString.h>
#include <ddcLib/ddcPrint.h>
#include <kernel/mmap.h>

char* PS1 = "\x1b[38;5;15m[\x1b[38;5;4mddm\x1b[38;5;1mOS\x1b[38;5;15m]> ";

struct vgatty mtty = { 0, 0, 20, 10, 0, 0 };

void run_command(char* str, int len)
{
	if (cstring_compare(str, "true"))
	{
		ddPrint_char('1');
		ddPrint_char('\n');
	}
	else if (cstring_compare(str, "false"))
	{
		ddPrint_char('0');
		ddPrint_char('\n');
	}
	else if (cstring_compare(str, "mstat -a"))
	{
		for (int i = 0; i < mmap_region_count; i++)
		{
			struct mmap_entry* mmap = (struct mmap_entry*)0x5000;
			mmap += i;
			print_memory_map(mmap);
		}
	}
	else if (cstring_compare(str, "mstat"))
	{
		for (int i = 0; i < mmap_usable_region_count; i++)
		{
			print_memory_map(mmap_usable_regions[i]);
		}
	}
}

void vgatty_handle_key(uint8t key)
{
	static uint8t buf[255] = {0};
	static int pos = 0;
	if (key == '\n')
	{
		ddPrint_char('\n');
		run_command(buf, pos);
		ddPrints(PS1);
		buf[0] = 0;
		pos = 0;
		return;
	}
	else if (key == '\b')
	{
		if (pos > 0)
		{
			ddPrint_char(key);
			buf[--pos] = 0;
		}
		return;
	}
	else
	{
		if (key)
		{
			buf[pos++] = key;
			buf[pos] = 0;
			ddPrint_char(key);
		}
	}
}

void init_vgatty(void)
{
	keyboard_set_focus(vgatty_handle_key, false);
	ddPrints(PS1);
}
