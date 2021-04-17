%macro PUSHAQ 0
	push rax
	push rcx
	push rdx
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro
%macro POPAQ 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
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

extern syscall
global isr105
isr105:
	PUSHAQ
	;mov r8, tstr
	call syscall
	POPAQ
	iretq

tstr:
	db "hi there how are you"
tstr_end:
