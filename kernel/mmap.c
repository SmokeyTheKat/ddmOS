#include <kernel/mmap.h>
#include <kernel/kernel.h>
#include <ddcLib/ddcPrint.h>
#include <ddcLib/ddcString.h>


multiboot_memory_map_t* mmap_usable_regions[10];
long mmap_usable_region_count = 0;


void print_memory_map(multiboot_memory_map_t* mmap)
{
	ddPrints("base: ");
	ddPrint_int(mmap->addr);
	ddPrints("  rlen: ");
	ddPrint_int(mmap->len);
	ddPrints("  mtype: ");
	ddPrint_int(mmap->type);
	ddPrints("\n");
}

void init_mmap_regions(void)
{
	for (multiboot_memory_map_t* mmap = (multiboot_memory_map_t*)(multiboot_uint64_t)multiboot_ptr->mmap_addr;
		(unsigned long) mmap < multiboot_ptr->mmap_addr + multiboot_ptr->mmap_length;
			mmap = (multiboot_memory_map_t *) ((unsigned long) mmap
			+ mmap->size + sizeof (mmap->size)))
	{
		if (mmap->type == 1)
		{
			mmap_usable_regions[mmap_usable_region_count++] = mmap;
		}
	}
}

multiboot_memory_map_t** mmap_get_usable_regions(void)
{
	return (multiboot_memory_map_t**)mmap_usable_regions;
}
