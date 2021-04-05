#include <kernel/mmap.h>
#include <ddcLib/ddcPrint.h>
#include <ddcLib/ddcString.h>


/*
struct mmap_entry* mmap_usable_regions[10];
long mmap_usable_region_count = 0;

void print_memory_map(struct mmap_entry* mmap)
{
	ddPrints("base: ");
	ddPrint_int(mmap->base_address);
	ddPrints("  rlen: ");
	ddPrint_int(mmap->region_length);
	ddPrints("  mtype: ");
	ddPrint_int(mmap->region_type);
	ddPrints("  memattrs: ");
	ddPrint_int(mmap->ext_attrs);
	ddPrints("\n");
}

void init_mmap_regions(void)
{
	for (int i = 0; i < mmap_region_count; i++)
	{
		struct mmap_entry* mmap = (struct mmap_entry*)0x5000;
		mmap += i;
		if (mmap->region_type == 1)
		{
			mmap_usable_regions[mmap_usable_region_count++] = mmap;
		}
	}
}

struct mmap_entry** mmap_get_usable_regions(void)
{
	return mmap_usable_regions;
}
*/
