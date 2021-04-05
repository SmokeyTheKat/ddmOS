[bits 32]
extern long_mode_start

global _start
section .text
_start:
	mov dword[multiboot_magic], eax
	mov dword[multiboot_ptr], ebx

	mov esp, stack_top

	mov ebx, str
	call print_string

	;call detect_multiboot
	call detect_cpuid
	call detect_long_mode

	call init_id_paging
	call enable_paging

	lgdt [gdt64.base]
	jmp gdt64.code_segment:long_mode_start

	hlt



%include "boot/print.asm"
%include "boot/paging.asm"
%include "boot/cpuid.asm"
%include "boot/gdt.asm"

section .data
str: db "Test string :)",0

global multiboot_ptr
multiboot_ptr: dd 0
global multiboot_magic
multiboot_magic: dd 0


section .bss
align 4096
page_table_l4:
	resb 4096
page_table_l3:
	resb 4096
page_table_l2:
	resb 4096
stack_bottom:
	resb 4096 * 4
stack_top:
