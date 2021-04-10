#include <kernel/fs.h>
#include <kernel/ata.h>
#include <kernel/mbank.h>
#include <ddcLib/ddcMem.h>
#include <ddcLib/ddcPrint.h>

uint32t fs_head = 0;

void fs_locate(void)
{
	char* target = malloc(256);
	int i = 0;
	for (i = 0; *(uint64t*)target != 2348054217241543273; i++)
		ata_read_sectors((char*)target, i, 1);
	i--;
	fs_head = i;
	free(target);
}
uint32t fs_get_location(void)
{
	return fs_head;
}
void fs_print_name(uint32t sec)
{
	struct fs_folder f = {0};
	char* buf = malloc(512);
	ata_read_sectors(buf, fs_head+sec, 1);
	ddMem_copy((char*)f.data, buf, 512);
	free(buf);
	ddPrints("    ");
	ddPrint_int(f.type);
	ddPrints(" - ");
	ddPrint_int(sec);
	ddPrints(" - ");
	ddPrints((char*)f.name);
	ddPrints("\n");
}
void fs_ls(uint32t sec)
{
	struct fs_folder f = {0};
	char* buf = malloc(512);
	ata_read_sectors(buf, fs_head+sec, 1);
	ddMem_copy((char*)f.data, buf, 512);
	free(buf);
	ddPrints((char*)f.name);
	ddPrints("\n");
	int pos = 0;
	while (f.nodes[pos])
	{
		fs_print_name(f.nodes[pos]);
		pos++;
	}

}

void init_fs(void)
{
	fs_locate();
}
