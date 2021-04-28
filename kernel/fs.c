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
	char* buf = malloc(512);
	ata_read_sectors(buf, fs_head+sec, 1);
	struct fs_folder f = *(struct fs_folder*)buf;
	free(buf);
	ddPrints("    ");
	ddPrint_int(sec);
	ddPrints(" - ");
	ddPrints((char*)f.name);
	if (f.type == 1)
		ddPrints("/");
	ddPrints("\n");
}
void fs_ls(uint32t sec)
{
	char* buf = malloc(512);
	ata_read_sectors(buf, fs_head+sec, 1);
	struct fs_folder f = *(struct fs_folder*)buf;
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

void fs_mkdir(uint32t sec, char* name)
{
	char* buf = malloc(512);

	ata_read_sectors(buf, fs_head, 1);
	struct fs_header hed = *(struct fs_header*)buf;

	ata_read_sectors(buf, fs_head+sec, 1);
	struct fs_folder fld = *(struct fs_folder*)buf;

	int i = 0;
	while (fld.nodes[i] != 0) i++;
	int ndir = ++hed.used;
	fld.nodes[i] = ndir;
	struct fs_folder newf = {0};
	newf.type = 1;
	ddMem_copy(newf.name, name, cstring_length(name));
	newf.self = ndir;
	newf.nodes[0] = sec;
	ata_write_sectors(fs_head, 1, &hed);
	ata_write_sectors(fs_head+sec, 1, &fld);
	ata_write_sectors(fs_head+ndir, 1, &newf);
	free(buf);
}

struct fs_folder fs_get_folder_data(uint32t sec)
{
	char* buf = malloc(512);
	ata_read_sectors(buf, fs_head+sec, 1);
	struct fs_folder f = *(struct fs_folder*)buf;
	free(buf);
	return f;
}
struct fs_file fs_get_file_data(uint32t sec)
{
	char* buf = malloc(512);
	ata_read_sectors(buf, fs_head+sec, 1);
	struct fs_file f = *(struct fs_file*)buf;
	free(buf);
	return f;
}
uint64t fs_get_file_size(uint32t sec)
{
	char* buf = malloc(512);
	ata_read_sectors(buf, fs_head+sec, 1);
	struct fs_file f = *(struct fs_file*)buf;
	free(buf);
	return f.size;
}

void init_fs(void)
{
	fs_locate();
}
