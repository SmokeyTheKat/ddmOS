#include "../include/kernel/memBank.h"

#define DEFAULT_REPO_SIZE 4096

static struct memBank mbank;

void* memBank_get_real_addr(struct memBank bank, void* bankAddr)
{
	return bank.addr + bankAddr;
}

struct MBDN* memBank_get_free_repo(struct memBank bank)
{
	struct MBDN* rptr = bank.headRepo;
	while (rptr->next != nullptr && !rptr->next.isFree)
	{
		rptr = rptr->next;
	}
	if (rptr->next == nullptr)
	{
		//rptr->next = make_memRepo(rptr->
	}
	else if (rptr->next.isFree == true)
	{

	}
}

void init_memBank(void)
{
	mbank.addr = nullptr + 2048;
	mbank.size = 8192;
	mbank.vauleAddr = nullptr;
	mbank.vauleSize = 2048;
	struct memRepo mrepo = make_memRepo(memBank_get_real_addr(mbank, 0x00000000), DEFAULT_REPO_SIZE, -1, false);
	struct MBDN hrepo = make_MBDN(nullptr, nullptr, mrepo);
	mbank.headRepo = hrepo;
	mbank.isLocked = false;
}

struct memRepo make_memRepo(void* addr, uint64t size, int32t uid, bool locked)
{
	struct memRepo output;
	output.address = addr;
	output.size = size;
	output.uid = uid;
	output.isLocked = locked;
	output.isFree = true;
	return output;
}

struct MBDN make_MBDN(struct MBDN* next, struct MBDN* prev, struct memRepo repo)
{
	struct MBDN output;
	output.next = next;
	output.prev = prev;
	output.repo = repo;
	return output;
}
