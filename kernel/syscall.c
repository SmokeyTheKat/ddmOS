#include <kernel/syscall.h>
#include <kernel/vga.h>
#include <kernel/idt.h>
#include <kernel/beep.h>
#include <ddcLib/ddcDef.h>
#include <ddcLib/ddcPrint.h>
#include <ddcLib/ddcString.h>

void __syscall_print(uint64t r[8]);
void __syscall_print_null_term(uint64t r[8]);
void __syscall_beep(uint64t r[8]);

void(*__syscall_vector[])(uint64t[8]) = {
	[0]=__syscall_print,
	[1]=__syscall_print_null_term,
	[2]=__syscall_beep,
};

void syscall(void)
{
	uint64t rcx;
	uint64t r[8];
	asm volatile("\t movq %%rcx,%0":"=r"(rcx));
	asm volatile("\t movq %%r8,%0":"=r"(r[0]));
	asm volatile("\t movq %%r9,%0":"=r"(r[1]));
	asm volatile("\t movq %%r10,%0":"=r"(r[2]));
	asm volatile("\t movq %%r11,%0":"=r"(r[3]));
	asm volatile("\t movq %%r12,%0":"=r"(r[4]));
	asm volatile("\t movq %%r13,%0":"=r"(r[5]));
	asm volatile("\t movq %%r14,%0":"=r"(r[6]));
	asm volatile("\t movq %%r15,%0":"=r"(r[7]));
	__syscall_vector[rcx](r);
}

void __syscall_print(uint64t r[8])
{
	char* str = (char*)r[0];
	vga_write(str, r[1]);
}
void __syscall_print_null_term(uint64t r[8])
{
	vga_write((void*)r[0], cstring_length((char*)r[0]));
}
void __syscall_beep(uint64t r[8])
{
	pcspk_beep(r[0], r[1]);
}

void init_syscalls(void)
{
	idt_set_isr(0x69, syscall);
}
