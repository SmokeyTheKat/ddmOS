#ifndef __ddmos_task_h__
#define __ddmos_task_h__

#include "../sys/system.h"

struct task
{
	regs32t regs;
	struct task* nextTask;
};

void init_task(void);
void task_create(struct task* task, void(*code)(void), uint32t flags, uint32t* memRepo);
void task_switch(regs32t* newRegs, regs32t* oldRegs);
void task_yield(void);

#endif
