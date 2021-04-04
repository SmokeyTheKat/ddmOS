#include <kernel/mbank.h>
#include <kernel/mmap.h>
#include <ddcLib/ddcPrint.h>

struct mbank mbank_main;

struct mbank_repo make_mbank_repo(struct mbank_repo* next, struct mbank_repo* prev, uint64t addr, uint64t cap, uint64t size, uint32t id)
{
	struct mbank_repo output;
	output.addr = addr;
	output.capacity = cap;
	output.size = size;
	output.id = id;
	output.isfree = true;
	output.next = next;
	output.prev = prev;
	return output;
}

void init_mbank(void)
{
	struct mmap_entry mme_null = (struct mmap_entry){0};
	mme_null.region_length = 0;
	struct mmap_entry* largest = &mme_null;
	largest = mmap_usable_regions[1];
/*
	for (int i = 0; i < mmap_usable_region_count; i++)
	{
		if (mmap_usable_regions[i]->region_length > largest->region_length)
			largest = mmap_usable_regions[i];
	}
*/

	ddPrints("starting mbank at ");
	ddPrint_int(largest->base_address);
	ddPrints("\n");

	mbank_main.base = largest->base_address;
	mbank_main.size = largest->region_length-0x10;
	*(struct mbank_repo*)mbank_main.base = make_mbank_repo(0, 0,
						mbank_main.base+sizeof(struct mbank_repo),
						16, 16, 0);
	mbank_main.head = (struct mbank_repo*)mbank_main.base;
}

void mbank_repo_append_new(struct mbank_repo* mbr, uint64t size)
{
	uint64t naddr = mbr->addr + mbr->capacity + sizeof(struct mbank_repo);
	*(struct mbank_repo*)(naddr-sizeof(struct mbank_repo)) = make_mbank_repo(0, mbr,
					naddr, size, size, mbr->id+1);
	mbr->next = (struct mbank_repo*)(naddr-sizeof(struct mbank_repo));
}

void free(void* ptr)
{
	struct mbank_repo* mbr = mbank_main.head;
	while (mbr && mbr->addr != (uint64t)ptr)
	{
		mbr = mbr->next;
	}
	mbr->isfree = true;
}
void* malloc(uint64t size)
{
	struct mbank_repo* mbr = mbank_main.head;
	while (mbr->next && !(mbr->next->isfree && mbr->next->capacity >= size))
	{
		ddPrints("loop\n");
		mbr = mbr->next;
	}
	if (!mbr->next)
	{
		mbank_repo_append_new(mbr, size);
		mbr = mbr->next;
		mbr->isfree = false;
	}
	else if (mbr->next->isfree)
	{
		mbr = mbr->next;
		mbr->size = size;
		mbr->isfree = false;
	}
	return (void*)mbr->addr;
}
