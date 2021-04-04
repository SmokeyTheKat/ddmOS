jmp enter_protected_mode

%include "boot/print.s"
%include "boot/memdect.s"
%include "boot/gdt.s"


enter_protected_mode:
	call detect_memory
	call enable_a20
	cli
	lgdt [gdt_dscr]
	mov eax, cr0		;set protected mode
	or eax, 1		;
	mov cr0, eax
	jmp codeseg:start_protected_mode

	jmp $

enable_a20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret


[bits 32]

%include "boot/cpuid.s"
%include "boot/paging.s"

start_protected_mode:
	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov ebp, 0x50000
	mov esp, ebp

	call detect_cpuid
	call detect_long_mode
	call init_id_paging
	call edit_gdt

	jmp codeseg:start_long_mode

[bits 64]
[extern kmain]

;%include "kernel/sidt.s"

start_long_mode:
	mov edi, 0xb8000
	mov rax, 0x0000000000000000
	mov ecx, 500
	rep stosq
	call kmain
	jmp $
	

times 2048-($-$$) db 0
