#ifndef __ddmos_membank_h__
#define __ddmos_membank_h__

#include "../ddcDef.h"

struct memRepo
{
	void* address;
	uint64t size;
	int32t uid;
	bool isLocked;
	bool isCache;
	bool isEmpty;
};

struct memBank
{
	void* bankAddr;
	uint64t bankSize;
	void* bankVaultAddr;
	void* bankVaultLength;
	struct memRepo* headRepo;
	bool isLocked;
};


#endif
