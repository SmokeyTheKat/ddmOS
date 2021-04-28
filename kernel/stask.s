[bits 64]
MEM_LOCATION equ 0x1000000

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

extern ata_read_sectors
extern fs_get_location
extern fs_get_file_size
extern ddMem_copy

lsec: dq 0
lsize: dq 0

global exec
exec:
	push rbp
	mov rbp, rsp

	mov qword[lsec], rdi

	call fs_get_location
	push rax

	mov rdi, qword[lsec]
	call fs_get_file_size
	mov qword[lsize], rax
	pop rsi
	add rsi, qword[lsize]
	add rsi, 1
	
	mov rdi, MEM_LOCATION

	call ata_read_sectors

	PUSHAQ

	mov rax, MEM_LOCATION
	add rax, 24
	call rax

	POPAQ

	pop rbp
	ret
	

