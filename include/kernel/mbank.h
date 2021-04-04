#ifndef __DDMOS_MBANK_H__
#define __DDMOS_MBANK_H__

#include <ddcLib/ddcDef.h>

struct mbank_repo
{
	uint64t addr;
	uint64t size;
	uint64t capacity;
	int32t id;
	bool isfree;
	struct mbank_repo* next;
	struct mbank_repo* prev;
};

struct mbank
{
	uint64t base;
	uint64t size;
	struct mbank_repo* head;
	bool locked;
};

void init_mbank(void);
struct mbank_repo make_mbank_repo(struct mbank_repo* next, struct mbank_repo* prev, uint64t addr, uint64t cap, uint64t size, uint32t id);
void* malloc(uint64t size);
void free(void* ptr);

#endif
