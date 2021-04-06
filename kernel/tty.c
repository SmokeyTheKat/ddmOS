#include <kernel/tty.h>
#include <ddcLib/ddcString.h>
#include <ddcLib/ddcPrint.h>
#include <ddcLib/ddcMem.h>
#include <kernel/mmap.h>
#include <kernel/mbank.h>
#include <kernel/system.h>
#include <kernel/beep.h>
#include <user/test.c>

char* PS1 = "\x1b[38;5;15m[\x1b[38;5;4mddm\x1b[38;5;1mOS\x1b[38;5;15m]> ";

struct vgatty mtty = { 0, 0, 20, 10, 0, 0 };

void run_command(char* str, int len)
{
	int argc = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == ' ') argc++;

	char** argv = malloc(sizeof(char*)*argc);
	int pos = 0;
	char mbuf[255] = {0};
	int mpos = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			argv[pos] = malloc(sizeof(char)*mpos+1);
			ddPrints("mpos = ");
			ddPrint_int(mpos);
			ddPrints("\n");
			//system_sleep(10000000000);
			int j = 0;
			for (j = 0; j < mpos; j++)
				argv[pos][j] = 'a';
			argv[pos][j] = 0;
			//ddMem_copy(argv[pos], mbuf, mpos);
			mpos = 0;
			pos++;
		}
		else mbuf[mpos++] = str[i];
	}

	if (cstring_compare(str, "true"))
	{
		ddPrint_char('1');
		ddPrint_char('\n');
	}
	else if (cstring_compare_length(str, "test", 4))
	{
		test(argc, argv);
	}
	else if (cstring_compare(str, "false"))
	{
		ddPrint_char('0');
		ddPrint_char('\n');
	}
	else if (cstring_compare_length(str, "beep", 4))
	{
		char n1b[10] = {0};
		ddString n1 = make_ddString_from_buf(n1b, 10);
		for (int i = 5; i < len; i++)
		{
			if (str[i] == ' ')
				break;
			ddString_push_char_back(&n1, str[i]);
		}
		char n2b[10] = {0};
		ddString n2 = make_ddString_from_buf(n2b, 10);
		for (int i = 5 + n1.length+1; i < len; i++)
		{
			if (str[i] == ' ')
			{
				break;
			}
			ddString_push_char_back(&n2, str[i]);
		}
		beep(ddString_to_int(n1), ddString_to_int(n2));
	}
	else if (cstring_compare(str, "minfo"))
	{
		extern const char minfo[];
		ddPrints((char*)minfo);
	}
	else if (cstring_compare(str, "mstat"))
	{
		for (int i = 0; i < mmap_usable_region_count; i++)
		{
			print_memory_map(mmap_usable_regions[i]);
		}
	}
	else if (cstring_compare(str, "mbtest"))
	{
		ddPrints("running mbank test\n");
		long len = 100000;
		char* a = malloc(len);
		for (int i = 0; i < len; i++)
			a[i] = 234514327598;

		ddPrints("malloc a 100 = ");	
		ddPrint_int((long)a);
		ddPrints("\n");	

		char* b = malloc(20);
		ddPrints("malloc b 20 = ");	
		ddPrint_int((long)b);
		ddPrints("\n");	

		char* c = malloc(20);
		ddPrints("malloc c 75 = ");	
		ddPrint_int((long)c);
		ddPrints("\n");	

		free(b);
		ddPrints("free b\n");	

		b = malloc(20);
		ddPrints("malloc b 20 = ");	
		ddPrint_int((long)b);
		ddPrints("\n");	

		ddPrints("good\n");
	}
/*
	for (int i = 0; i < argc; i++)
		free(argv[i]);
	free(argv);
*/
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
