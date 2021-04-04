#ifndef __DDMOS_MMAP_H__
#define __DDMOS_MMAP_H__

#include <ddcLib/ddcDef.h>

struct mmap_entry
{
	uint64t base_address;
	uint64t region_length;
	uint32t region_type;
	uint32t ext_attrs;
};

extern uint8t mmap_region_count;
extern long mmap_usable_region_count;
extern struct mmap_entry* mmap_usable_regions[10];

void print_memory_map(struct mmap_entry* mmap);
struct mmap_entry** mmap_get_usable_regions(void);
void init_mmap_regions(void);


#endif
