#include "../include/kernel/memBank.h"
#include "../include/kernel/kernel.h"
#include "../include/kernel/tty.h"

#define DEFAULT_REPO_SIZE 4096

static struct memBank mbank;
static char* memSpace;

uint64t memBank_get_real_address(struct memBank bank, uint64t bankAddr)
{
	return bank.address + bankAddr;
}

static void int_to_cstring(uint64t v, char* o, int len)
{
	if (v == 0)
	{
		o[0] = '0';
		o[1] = '\0';
		return;
	}
	char sg = '+';
	if (v < 0)
	{
		sg = '-';
		v *= -1;
	}
	for (uint64t i = 0; i < len; i++)
		o[i] = '0';
	o[len-1] = '\0';
	uint64t pos = len-2;
	while (v)
	{
		uint64t x = v % 10;
		v /= 10;
		o[pos] = '0' + x;
		pos--;
	}
	o[pos] = sg;
}

struct MBDN* memBank_get_free_repo(struct memBank bank, uint64t size)
{
	struct MBDN* rptr = bank.headRepo;
	while (rptr->next != nullptr && !(rptr->next->repo.isFree && rptr->next->repo.size <= size))
	{
		rptr = rptr->next;
	}
	if (rptr->next == nullptr)
	{
		struct memRepo newRepo = make_memRepo(rptr->repo.address + rptr->repo.size + sizeof(struct MBDN), size, -1, false);
		struct MBDN newMBDN = make_MBDN(nullptr, rptr, newRepo);
		ddMem_copy(&(memSpace[newRepo.address - sizeof(struct MBDN)]), &newMBDN, sizeof(struct MBDN));
		rptr->next = (struct MBDN*)&(memSpace[newRepo.address - sizeof(struct MBDN)]);
		rptr->next->prev = rptr;
		rptr = rptr->next;
	}
	else if (rptr->next->repo.isFree == true)
	{
		struct memRepo newRepo = make_memRepo(rptr->next->repo.address, size, -1, false);
		struct MBDN newMBDN = make_MBDN(rptr->next->next, rptr->next->prev, newRepo);
		ddMem_copy(&(memSpace[newRepo.address - sizeof(struct MBDN)]), &newMBDN, sizeof(struct MBDN));
		rptr->next = (struct MBDN*)&(memSpace[newRepo.address - sizeof(struct MBDN)]);
		rptr->next->prev = rptr;
		rptr = rptr->next;
	}
	return rptr;
}

struct MBDN* memBank_get_repo_by_addr(struct memBank bank, void* addr)
{
	struct MBDN* rptr = bank.headRepo;
	while ((void*)&(memSpace[memBank_get_real_address(bank, rptr->next->repo.address)]) != addr)
	{
		rptr = rptr->next;
	}
	return rptr->next;
}

void init_memBank(void)
{
	mbank.address = nullptr+ 2048;
	mbank.size = 8192;
	mbank.vaultAddress = nullptr;
	mbank.vaultSize = 2048;
	struct memRepo mrepo = make_memRepo(0x00000000 + sizeof(struct MBDN), DEFAULT_REPO_SIZE, -1, false);
	struct MBDN hrepo = make_MBDN(nullptr, nullptr, mrepo);
	ddMem_copy(&(memSpace[mbank.address - sizeof(struct MBDN)]), &hrepo, sizeof(struct MBDN));
	mbank.headRepo = (struct MBDN*)&(memSpace[mbank.address - sizeof(struct MBDN)]);
	mbank.isLocked = false;
}

void* memBank_get_memory(uint64t size)
{
	struct MBDN* fetchedMemory = memBank_get_repo(mbank, size);
	char straddr[8];
	char strsize[8];
	char strtest[8];
	int_to_cstring(memBank_get_real_address(mbank, fetchedMemory->repo.address), straddr, 8);
	int_to_cstring(memBank_get_real_address(mbank, fetchedMemory->repo.size), strsize, 8);

	int_to_cstring(777, strtest, 8);
	//ddtty_write_cstring(&g_selectedTerm, "VALUE: ");
	//ddtty_write_cstring(&g_selectedTerm, strtest);
	//ddtty_write_cstring(&g_selectedTerm, "\"\n");

	ddtty_write_cstring(&g_selectedTerm, "\nALLOC: \"");
	ddtty_write_cstring(&g_selectedTerm, strsize);
	ddtty_write_cstring(&g_selectedTerm, " at ");
	ddtty_write_cstring(&g_selectedTerm, straddr);
	ddtty_write_cstring(&g_selectedTerm, "\"\n");
	return (void*)&(memSpace[memBank_get_real_address(mbank, fetchedMemory->repo.address)]);
}
void memBank_free_memory(void* addr)
{
/*
	struct MBDN* fetchedMemory = memBank_get_repo_by_addr(mbank, addr);
	fetchedMemory->repo.isFree = true;
	char str[8];
	char strsize[8];
	int_to_cstring(memBank_get_real_address(mbank, fetchedMemory->repo.address), str, 8);
	int_to_cstring(memBank_get_real_address(mbank, fetchedMemory->repo.size), strsize, 8);
	ddtty_write_cstring(&g_selectedTerm, "\n\nFREE: \"");
	ddtty_write_cstring(&g_selectedTerm, strsize);
	ddtty_write_cstring(&g_selectedTerm, " at ");
	ddtty_write_cstring(&g_selectedTerm, str);
	ddtty_write_cstring(&g_selectedTerm, "\"\n\n");
*/
}

struct MBDN* memBank_get_repo(struct memBank bank, uint64t size)
{
	return memBank_get_free_repo(bank, size);
}

struct memRepo make_memRepo(uint64t addr, uint64t size, int32t uid, bool locked)
{
	struct memRepo output;
	output.address = addr;
	output.size = size;
	output.uid = uid;
	output.isLocked = locked;
	output.isFree = false;
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
