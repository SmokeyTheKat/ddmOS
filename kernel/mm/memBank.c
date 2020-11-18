#include "../../include/kernel/mm/memBank.h"
#include "../../include/kernel/kernel.h"
#include "../../include/kernel/drivers/tty.h"
#include "../../include/kernel/drivers/vga.h"
#include "../../include/kernel/sys/fonts.h"

#define DEFAULT_REPO_SIZE 4096

static struct memBank mbank;
static char* memSpace;

uint64t memBank_get_real_address(struct memBank bank, uint64t bankAddr)
{
	return bank.address + bankAddr;
}

//temp... just add it 
static void int_to_cstring(int v, char* o, int len)
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
	for (int i = 0; i < len; i++)
		o[i] = '0';
	o[len-1] = '\0';
	int pos = len-2;
	while (v)
	{
		int x = v % 10;
		v /= 10;
		o[pos] = '0' + x;
		pos--;
	}
	o[pos] = sg;
}

void MBDN_append_new(struct MBDN* node, uint64t newRepoSize)
{
	struct memRepo newRepo = make_memRepo(node->repo.address + node->repo.size + sizeof(struct MBDN), newRepoSize, -1, false);
	struct MBDN newMBDN = make_MBDN(nullptr, node, newRepo);
	ddMem_copy(&(memSpace[newRepo.address - sizeof(struct MBDN)]), &newMBDN, sizeof(struct MBDN));
	node->next = (struct MBDN*)&(memSpace[newRepo.address - sizeof(struct MBDN)]);
	node->next->prev = node;
}

struct MBDN* memBank_get_free_repo(struct memBank bank, uint64t size)
{
	struct MBDN* rptr = bank.headRepo;
	while (rptr->next != nullptr && !(rptr->next->repo.isFree && rptr->next->repo.size >= size))
	{
		rptr = rptr->next;
	}
	if (rptr->next == nullptr)
	{
		MBDN_append_new(rptr, size);
		rptr = rptr->next;
	}
	else if (rptr->next->repo.isFree == true)
	{
		rptr->next->repo.isFree = false;
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
	mbank.address = nullptr + 2048;
	mbank.size = 8192;
	mbank.vaultAddress = nullptr;
	mbank.vaultSize = 2048;
	struct memRepo mrepo = make_memRepo(0x001000000 + sizeof(struct MBDN), 1, -1, false);
	struct MBDN hrepo = make_MBDN(nullptr, nullptr, mrepo);
	ddMem_copy(&(memSpace[mbank.address - sizeof(struct MBDN)]), &hrepo, sizeof(struct MBDN));
	mbank.headRepo = (struct MBDN*)&(memSpace[mbank.address - sizeof(struct MBDN)]);
	mbank.isLocked = false;


/*
	char straddr[8];
	char strsize[8];
	int_to_cstring(mbank.headRepo->repo.address, straddr,8);
	int_to_cstring(mbank.headRepo->repo.address, strsize,8);
	ddtty_write_cstring(&g_kernelTerm2, "ALLOC: \"");
	ddtty_write_cstring(&g_kernelTerm2, strsize);
	ddtty_write_cstring(&g_kernelTerm2, " at ");
	ddtty_write_cstring(&g_kernelTerm2, straddr);
	ddtty_write_cstring(&g_kernelTerm2, "\"\n");
*/
}
static int memoryUsed = 0;

static void memBank_update_graphics(void)
{
	int cptr = 5;
	for (int i = 0; i < 20; i++)
	{
		vga_draw_char(g_vgaFont[(int)(' ')], cptr, 6, 15, 0);
		cptr+=6;
	}
	cptr = 5;
	vga_draw_char(g_vgaFont[(int)('M')], cptr, 6, 15, 0);
	cptr+=6;
	vga_draw_char(g_vgaFont[(int)('E')], cptr, 6, 15, 0);
	cptr+=6;
	vga_draw_char(g_vgaFont[(int)('M')], cptr, 6, 15, 0);
	cptr+=6;
	vga_draw_char(g_vgaFont[(int)(':')], cptr, 6, 15, 0);
	cptr+=6;

	char ustr[8];
	int_to_cstring(memoryUsed, ustr, 8);
	for (int i = 0; i < 8; i++)
	{
		vga_draw_char(g_vgaFont[(int)(ustr[i])], cptr, 6, 15, 0);
		cptr+=6;
	}
}

void* memBank_alloc_memory(uint64t size)
{
	memoryUsed += size;
	memBank_update_graphics();
	struct MBDN* fetchedMemory = memBank_get_repo(mbank, size);
	return (void*)&(memSpace[memBank_get_real_address(mbank, fetchedMemory->repo.address)]);
}
void memBank_free_memory(void* addr)
{
	struct MBDN* fetchedMemory = memBank_get_repo_by_addr(mbank, addr);
	fetchedMemory->repo.isFree = true;
	if (fetchedMemory->next == nullptr)
		fetchedMemory->prev->next = nullptr;
	//memoryUsed -= fetchedMemory->repo.size;
	memBank_update_graphics();
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
