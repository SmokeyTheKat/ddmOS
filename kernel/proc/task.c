#include "../../include/kernel/proc/task.h"
#include "../../include/kernel/kernel.h"
#include "../../include/kernel/drivers/tty.h"

static struct task* activeTask;
static struct task mainTask;
static struct task otherTask;

static void otherMain(void)
{
	ddtty_write_cstring(&g_kernelTerm2, "OTHER MAIN FUNCTION\n");
	task_yield();
}

void init_task(void)
{
	asm volatile("movl %%cr3, %%eax; movl %%eax, %0;":"=m"(mainTask.regs.cr3)::"%eax");
	asm volatile("pushfl; movl (%%esp), %%eax; movl %%eax, %0; popfl;":"=m"(mainTask.regs.eflags)::"%eax");
	task_create(&otherTask, otherMain, mainTask.regs.eflags, (uint32t*)&(mainTask.regs.cr3));
	mainTask.nextTask = &otherTask;
	otherTask.nextTask = &mainTask;
	activeTask = &mainTask;
}

void task_create(struct task* task, void(*code)(), uint32t flags, uint32t* memRepo)
{
	task->regs.eax = 0;
	task->regs.ebx = 0;
	task->regs.ecx = 0;
	task->regs.edx = 0;
	task->regs.esi = 0;
	task->regs.edi = 0;
	task->regs.eflags = flags;
	task->regs.eip = (uint32t)code;
	task->regs.cr3 = (uint32t)*memRepo;
	//task->regs.esp = (uint32t) ;
}

void task_yield(void)
{
}
