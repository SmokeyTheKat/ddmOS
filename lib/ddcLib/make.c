#include "../../include/ddcLib/make.h"

typedef struct memoryData memoryData;

static uint8t* memspace;

struct memoryData
{
	uint64t memSpot;
	sizet size;
	bool used;
	bool inited;
	memoryData* next;
};

memoryData* memfoot;

__attribute__((constructor)) void init_memspace(void)
{
	memoryData ft;
	ft.memSpot = 0;
	ft.size = 0;
	ft.used = false;
	ft.inited = true;
	ft.next = nullptr;
	memfoot = &ft;
}

memoryData* make_get_free(sizet _size)
{
	memoryData* _p = memfoot;
	uint8t coff = 0;
	while (_p->used != false)
	{
		coff = _p->size + _p->size;
		_p = _p->next;
	}
	_p->used = true;
	_p->size = _size;
	_p->memSpot = coff;
	if (_p->inited != true)
	{
		memoryData ft;
		ft.memSpot = 0;
		ft.size = 0;
		ft.used = false;
		ft.inited = true;
		ft.next = nullptr;
		_p->next = &ft;
	}
	return _p;
}
sizet sp = 0;
void* make(sizet _size)
{
	memoryData* _f = make_get_free(_size);
	void* _o = (void*)&(memspace[_f->memSpot]);
	return _o;
}

void raze(void* _mem)
{
	memoryData* _p = memfoot;
	while (_p->memSpot != _mem)
	{
	}
	_p->used = false;
	_p->size = 0;
}
