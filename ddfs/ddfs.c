#include <stdlib.h>
#include <stdio.h>
#include <ddcDef.h>
#include <ddcString.h>
#include <ddcPrint.h>
#include <ddcMem.h>

char* fname;

struct fs_header
{
	union
	{
		struct
		{
			uint64t magic;
			uint32t used;
			uint64t size;
			uint64t root;
			char padding[484];
		}__attribute__((__packed__));
		char data[512];
	}__attribute__((__packed__));
}__attribute__((__packed__));
struct fs_file
{
	union
	{
		struct
		{
			char type;
			char name[20];
			uint32t self;
			uint32t size;
			char padding[479];
		}__attribute__((__packed__));
		char data[512];
	}__attribute__((__packed__));
}__attribute__((__packed__));
struct fs_folder
{
	union
	{
		struct
		{
			char type;
			char name[20];
			uint32t self;
			uint32t nodes[121];
			char padding[3];
		}__attribute__((__packed__));
		char data[512];
	}__attribute__((__packed__));
}__attribute__((__packed__));


ddString read_file(const char* path)
{
	FILE* fp = fopen(path, "r");
	if (fp == NULL) ddError("CANT OPEN FILE\n");
	fseek(fp, 0L, SEEK_END);
	long nb = ftell(fp) - 1;
	fseek(fp, 0L, SEEK_SET);
	char* buffer = calloc(nb+1, sizeof(char));
	fread(buffer, sizeof(char), nb, fp);
	fclose(fp);
	return make_ddString_length(buffer, nb);
}
void write_file(const char* path, char* data, uint64t length)
{
	data[length] = 0;
	FILE* fp = fopen(path, "w");
	if (fp == null) return;
	fwrite(data, sizeof(char), length, fp);
	fclose(fp);
}

void fs_pn(char* buf, int sec)
{
	struct fs_folder f = {0};
	mem_copy((char*)f.data, &buf[512*sec], 512);
	printf("	s%d - %s\n", sec, (char*)f.name);
}

void fs_ls(int sec)
{
	ddString data = read_file(fname);
	char* buf = data.cstr;
	struct fs_folder f = {0};
	mem_copy((char*)f.data, &buf[512*sec], 512);
	printf("%s\n", (char*)f.name);
	int pos = 0;
	while (f.nodes[pos])
	{
		fs_pn(buf, f.nodes[pos]);
		pos++;
	}
}


void print_data(ddString data)
{
	int xpos = 0;
	int ypos = 0;
	for (int i = 0; i < 10*512; i++)
	{
		printf("%02X ", (unsigned char)(data.cstr[i]));
		xpos++;
		if (xpos == 32)
		{
			printf("\n");
			xpos = 0;
			ypos++;
			if (ypos == 16)
			{
				printf("\n");
				ypos = 0;
			}
		}
	}
}

#define SO(x) (0x200*(x))

void set_sector(char* buf, int pos, void* stct)
{
	*(struct fs_header*)&buf[SO(pos)] = *(struct fs_header*)stct;
}

void init_fs(long size)
{
	char* buf = calloc(size*512, 1);
	struct fs_header header = {
		0x2095f6debc0a4269,
		1, 1,
	};
	struct fs_folder root = {
		1, "root\0               ",
		1,
		{ 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, },
		{0},
	};
	set_sector(buf, 0, &header);
	set_sector(buf, 1, &root);
	write_file(fname, buf, size*512);
}

void fs_touch(int dir, char* name, char* file)
{
	ddString data = read_file(fname);
	char* buf = data.cstr;
	struct fs_folder* fld = (struct fs_folder*)&buf[SO(dir)];
	struct fs_header* hed = (struct fs_header*)&buf[SO(0)];
	int i = 0;
	while (fld->nodes[i] != 0) i++;
	int ndir = ++hed->used;
	fld->nodes[i] = ndir;

	ddString fdata = read_file(file);
	uint32t len = (fdata.length/512)+1;

	hed->used += len;

	char bname[20] = {' '};
	mem_copy(bname, name, cstring_length(name));

	struct fs_file nfil = {
		0, "                    ",
		ndir, len,
		{0},
	};
	mem_copy(nfil.name, bname, 20);
	mem_copy(&buf[SO(ndir+1)], fdata.cstr, fdata.length);
	set_sector(buf, ndir, &nfil);
	write_file(fname, buf, data.length);
}

void fs_mkdir(int dir, char* name)
{
	ddString data = read_file(fname);
	char* buf = data.cstr;
	struct fs_folder* fld = (struct fs_folder*)&buf[SO(dir)];
	struct fs_header* hed = (struct fs_header*)&buf[SO(0)];
	int i = 0;
	while (fld->nodes[i] != 0) i++;
	int ndir = ++hed->used;
	fld->nodes[i] = ndir;
	char bname[20] = {' '};
	mem_copy(bname, name, cstring_length(name));
	struct fs_folder newf = {
		1, "                    ",
		ndir,
		{ dir, 0, 0, 0, 0,
		  0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, },
		{0},
	};
	mem_copy(newf.name, bname, 20);
	set_sector(buf, ndir, &newf);
	write_file(fname, buf, data.length);
}

int main(int argc, char** argv)
{
	if (argc <= 2) ddError("NO FILE PATH GIVEN\n");
	fname = argv[1];
	if (argv[2][0] == 'i' && argc == 4)
	{
		long size = ddString_to_int(make_constant_ddString(argv[3]));
		init_fs(size);
	}
	else if (argv[2][0] == 'l' && argc == 4)
	{
		int dir = ddString_to_int(make_constant_ddString(argv[3]));
		fs_ls(dir);
	}
	else if (argv[2][0] == 'd' && argc == 5)
	{
		int dir = ddString_to_int(make_constant_ddString(argv[3]));
		fs_mkdir(dir, argv[4]);
	}
	else if (argv[2][0] == 'f' && argc == 6)
	{
		int dir = ddString_to_int(make_constant_ddString(argv[3]));
		fs_touch(dir, argv[4], argv[5]);
	}
	return 0;
}
