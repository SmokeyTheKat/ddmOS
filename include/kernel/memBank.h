#ifndef __ddmos_membank_h__
#define __ddmos_membank_h__

#include "../ddcDef.h"

struct membank;
struct memRepo;
struct MBDN;

struct memBank
{
	uint64t address;
	uint64t size;
	uint64t vaultAddress;
	uint64t vaultSize;
	struct MBDN* headRepo;
	bool isLocked;
};

struct memRepo
{
	uint64t address;
	uint64t size;
	int32t uid;
	bool isFree;
	bool isLocked;
	bool isCache;
	bool isEmpty;
};

struct MBDN
{
	struct MBDN* next;
	struct MBDN* prev;
	struct memRepo repo;
};

void init_memBank(void);
uint64t memBank_get_real_addr(struct memBank bank, uint64t bankAddr);
struct MBDN* memBank_get_free_repo(struct memBank bank, uint64t size);
struct MBDN* memBank_get_repo(struct memBank bank, uint64t size);
void* memBank_alloc_memory(uint64t size);
void memBank_free_memory(void* addr);

struct memRepo make_memRepo(uint64t addr, uint64t size, int32t uid, bool locked);

struct MBDN make_MBDN(struct MBDN* next, struct MBDN* prev, struct memRepo repo);
void MBDN_append_new(struct MBDN* node, uint64t newRepoSize);

#endif
