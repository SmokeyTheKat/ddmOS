#include "../../include/ddcLib/make.h"

static uint8t* memspace;

/*
typedef struct memdesc memdesc;


struct memdesc
{
	uint64t memSpot;
	sizet size;
	bool used;
	bool inited;
	memdesc* next;
};

memdesc* memfoot;

memdesc make_memdesc(void)
{
	memdesc _o;
	_o.inited = true;
	_o.used = false;
	_o.memSpot = null;
	_o.next = nullptr;
	return _o;
}

__attribute__((constructor)) void init_memspace(void)
{
	(*memfoot) = make_memdesc();
}

memdesc* make_get_free(sizet _size)
{
	memdesc* _p = memfoot;
	uint64t coff = 0;
	while(_p->used != false)
	{
		coff = _p->used + _p->size;
		_p = _p->next;
	}
	if (_p->inited != true)
	{
		*(_p) = make_memdesc();
		_p->used = true;
	}
	_p->memSpot = coff;
	return _p;
}
*/
sizet sp = 0;
void* get_memroy(sizet _size)
{
	//memdesc* _f = make_get_free(_size);
	void* _o = (void*)&(memspace[sp]);
	sp += _size;
	return _o;
}

void free_memory(void* _mem)
{
	char c = *((char*)_mem);
	if (c=='0')
		return;
/*
	memdesc* _p = memfoot;
	while (_p->memSpot != _mem)
	{
	}
	_p->used = false;
	_p->size = 0;
*/
}
