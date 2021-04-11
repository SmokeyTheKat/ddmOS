%macro PUSHAQ 0
	push rax
	push rcx
	push rdx
	push r8
	push r9
	push r10
	push r11
%endmacro
%macro POPAQ 0
	pop r11
	pop r10
	pop r9
	pop r8
	pop rdx
	pop rcx
	pop rax
%endmacro

extern _idt
idt_dscr:
	dw 4095
	dq _idt

global load_idt
load_idt:
	lidt[idt_dscr]
	sti
	ret

extern isr1_handler
global isr1
isr1:
	PUSHAQ
	call isr1_handler
	POPAQ
	iretq

extern isr128_handler
global isr128
isr128:
	PUSHAQ
	call isr128_handler
	POPAQ
	iretq
