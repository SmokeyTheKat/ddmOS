#ifndef __DDMOS_MMAP_H__
#define __DDMOS_MMAP_H__

#include <ddcLib/ddcDef.h>
#include <boot/multiboot.h>

extern multiboot_memory_map_t* mmap_usable_regions[10];
extern long mmap_usable_region_count;

void print_memory_map(multiboot_memory_map_t* mmap);
multiboot_memory_map_t** mmap_get_usable_regions(void);
void init_mmap_regions(void);


#endif
