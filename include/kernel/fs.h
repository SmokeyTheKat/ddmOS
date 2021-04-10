#ifndef __DDMOS_FS_H__
#define __DDMOS_FS_H__

#include <ddcLib/ddcDef.h>

struct fs_file
{
	union
	{
		struct
		{
			char type;
			char name[20];
			uint32t parent;
			uint64t size;
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
			uint32t nodes[15];
			char padding[11];
		}__attribute__((__packed__));
		char data[512];
	}__attribute__((__packed__));
}__attribute__((__packed__));

void init_fs(void);
uint32t fs_get_location(void);
void fs_ls(uint32t sec);

#endif
