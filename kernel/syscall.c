#include <kernel/syscall.h>
#include <kernel/vga.h>
#include <kernel/idt.h>
#include <kernel/beep.h>
#include <ddcLib/ddcDef.h>
#include <ddcLib/ddcPrint.h>

void __syscall_print(int64t str, int64t len);
void __syscall_beep(int64t freq, int64t len);

void(*__syscall_vector[])(void) = {
	[0]=(void(*)(void))__syscall_print,
	[1]=(void(*)(void))__syscall_beep,
};

void syscall(void)
{
	long rcx;
	asm("\t movq %%rcx,%0":"=r"(rcx));
	__syscall_vector[rcx]();
}

void __syscall_print(int64t str, int64t len)
{
	vga_write((void*)str, len);
}
void __syscall_beep(int64t freq, int64t len)
{
	pcspk_beep(freq, len);
}

void init_syscalls(void)
{
	idt_set_isr(128, (void(*)(void))syscall);
}
