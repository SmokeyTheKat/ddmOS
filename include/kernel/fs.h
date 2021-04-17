#ifndef __DDMOS_FS_H__
#define __DDMOS_FS_H__

#include <ddcLib/ddcDef.h>

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

void init_fs(void);
uint32t fs_get_location(void);
void fs_ls(uint32t sec);
void fs_mkdir(uint32t sec, char* name);
struct fs_folder fs_get_folder_data(uint32t sec);
struct fs_file fs_get_file_data(uint32t sec);

#endif
