#ifndef __ddmos_membank_h__
#define __ddmos_membank_h__

#include "../ddcDef.h"

struct membank;
struct memRepo;
struct MBDN;

struct memBank
{
	void* addr;
	uint64t size;
	void* vaultAddr;
	uint64t vaultLength;
	struct MBDN* headRepo;
	bool isLocked;
};

struct memRepo
{
	void* address;
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
void memBank_get_real_addr(struct memBank bank, void* bankAddr);
struct MBDN* memBank_get_free_repo(struct memBank bank);

struct memRepo make_memRepo(void* addr, uint64t size, int32t uid, bool locked);

struct MBDN make_MBDN(struct MBDN* next, struct MBDN* prev, struct memRepo repo);

#endif
