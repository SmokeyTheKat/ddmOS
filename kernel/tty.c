#include <kernel/tty.h>
#include <ddcLib/ddcString.h>
#include <ddcLib/ddcPrint.h>
#include <ddcLib/ddcMem.h>
#include <kernel/mmap.h>
#include <kernel/mbank.h>
#include <kernel/system.h>
#include <kernel/beep.h>
#include <kernel/ata.h>
#include <kernel/fs.h>
#include <elf.h>
#include <user/test.c>

#define PUSHAQ \
	asm volatile("push %rax"); \
	asm volatile("push %rcx"); \
	asm volatile("push %rdx"); \
	asm volatile("push %rdi"); \
	asm volatile("push %rsi"); \
	asm volatile("push %r8"); \
	asm volatile("push %r9"); \
	asm volatile("push %r10"); \
	asm volatile("push %r11"); \
	asm volatile("push %r12"); \
	asm volatile("push %r13"); \
	asm volatile("push %r14"); \
	asm volatile("push %r15")

#define POPAQ \
	asm volatile("pop %r15"); \
	asm volatile("pop %r14"); \
	asm volatile("pop %r13"); \
	asm volatile("pop %r12"); \
	asm volatile("pop %r11"); \
	asm volatile("pop %r10"); \
	asm volatile("pop %r9"); \
	asm volatile("pop %r8"); \
	asm volatile("pop %rsi"); \
	asm volatile("pop %rdi"); \
	asm volatile("pop %rdx"); \
	asm volatile("pop %rcx"); \
	asm volatile("pop %rax")

char* PS1 = "\x1b[38;5;15m[\x1b[38;5;4mddm\x1b[38;5;1mOS\x1b[38;5;15m]> ";

struct vgatty mtty = { 0, 0, 20, 10, 0, 0 };

uint32t dir = 1;

void run_command(char* str, int len)
{
/*
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
*/

	if (cstring_compare(str, "true"))
	{
		ddPrint_char('1');
		ddPrint_char('\n');
	}
	else if (cstring_compare_length(str, "test", 4))
	{
		extern char test_program[];
		asm("call test_program\n");
		(void)test_program;
		//((void(*)(void))(char*)(test_program))();
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
		pcspk_beep(ddString_to_int(n1), ddString_to_int(n2));
	}
	else if (cstring_compare_length(str, "exec", 4))
	{
		if (len <= 5) return;
		uint32t sec = ddString_to_int(make_constant_ddString(str+3));
/*
		struct fs_file f = fs_get_file_data(sec);
		struct elf_header* elfd = (struct elf_header*)0x1000000;
		ata_read_sectors(elfd, fs_get_location()+sec+1, f.size);
		PUSHAQ;
		asm volatile("movq %0, %%rsp"::"r"((uint64t)elfd+((f.size+100)*512)));
		asm volatile("movq %0, %%rbp"::"r"((uint64t)elfd+((f.size+100)*512)));
		//char* tmp = (char*)((uint64t)elfd + (uint64t)(f.size*512));
		//ddMem_copy(tmp, elfd->entry, f.size*512);
		//ddMem_copy((char*)0x1000000, tmp, f.size*512);
		asm volatile("call %0"::"r"((char*)elfd->entry));
		POPAQ;
*/
		extern void exec(uint64t sec);
		exec(sec);
	}
	else if (cstring_compare_length(str, "cat", 3))
	{
		if (len <= 4) return;
		uint32t sec = ddString_to_int(make_constant_ddString(str+3));
		struct fs_file f = fs_get_file_data(sec);
		char* data = malloc(f.size*512);
		ata_read_sectors(data, fs_get_location()+sec+1, f.size);
		ddPrints(data);
		ddPrints("\n");
		free(data);
	}
	else if (cstring_compare_length(str, "cd", 2))
	{
		if (len <= 3) return;
		dir = ddString_to_int(make_constant_ddString(str+3));
	}
	else if (cstring_compare_length(str, "mkdir", 5))
	{
		fs_mkdir(dir, str+6);
	}
	else if (cstring_compare(str, "ls"))
	{
		fs_ls(dir);
	}
	else if (cstring_compare_length(str, "ls", 2))
	{
		if (len <= 3) return;
		fs_ls(ddString_to_int(make_constant_ddString(str+3)));
	}
	else if (cstring_compare_length(str, "plba", 4))
	{
		if (len <= 5) return;
		char* target = malloc(256);
		ata_read_sectors((char*)target, ddString_to_int(make_constant_ddString(str+5)), 1);
		ddPrints(target);
		ddPrints("\n");
		free(target);
	}
	else if (cstring_compare(str, "findfs"))
	{
		ddPrints("fs located at ");
		ddPrint_int(fs_get_location());
		ddPrints("\n");
	}
	else if (cstring_compare_length(str, "find", 4))
	{
		if (len <= 5) return;
		char* target = malloc(256);
		int i = 0;
		int flen = cstring_length(str+5);
		for (i = 0; !cstring_compare_length(target, str+5, flen); i++)
		{
			ata_read_sectors((char*)target, i, 1);
		}
		i--;
		ddPrints("found at lba ");
		ddPrint_int(i);
		ddPrints("\n");
		free(target);
	}
	else if (cstring_compare(str, "print"))
	{
		ddPrints("TEST\n");
	}
	else if (cstring_compare(str, "atar"))
	{
		ddPrints("READING FIRST 2 BYTES FROM DISK\n");
		char* target = malloc(256);
		ata_read_sectors((char*)target, 0x00, 1);
		ddPrint((char*)target, 2);
		free(target);
	}
	else if (cstring_compare(str, "ataw"))
	{
		ddPrints("WRITING FIRST 2 BYTES ON DISK AS 'YO'\n");
		char* target = malloc(256);
		ata_read_sectors((char*)target, 0x00, 1);
		target[0] = 'Y';
		target[1] = 'O';
		ata_write_sectors(0x00, 1, target);
		free(target);
	}
	else if (cstring_compare(str, "poweroff"))
	{
		system_poweroff();
	}
	else if (cstring_compare(str, "reboot"))
	{
		system_reboot();
	}
	else if (cstring_compare(str, "clear"))
	{
		vga_clear();
		vga_move_cursor(0, 0);
		vga_update_cursor();
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
		long len = 100;
		char* a = malloc(len);
		for (int i = 0; i < len; i++)
			a[i] = 23;

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
		run_command((char*)buf, pos);
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
}
void start_vgatty(void)
{
	ddPrints(PS1);
}
