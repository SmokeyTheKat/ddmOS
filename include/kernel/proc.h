#ifndef __DDMOS_PROC_H__
#define __DDMOS_PROC_H__

#include <ddcLib/ddcDef.h>

struct regs
{
	uint64t rax;
	uint64t rcx;
	uint64t rdx;
	uint64t rbx;
	uint64t rsp;
	uint64t rbp;
	uint64t rsi;
	uint64t rdi;
	uint64t rip;
	uint64t eflags;
	uint64t cr3;
};

struct process
{
	struct process* next;
	struct process* prev;
	char* name;
	uint32t pid;
	struct regs context;
};

#endif
