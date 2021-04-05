detect_multiboot:
	cmp eax, 0x36d76289
	jne .error
	ret
.error:
	mov ebx, multiboot_error
	call print_string
	hlt

detect_cpuid:
	pushfd
	pop eax
	mov ecx, eax
	xor eax, 1 << 21
	push eax
	popfd
	pushfd
	pop eax
	push ecx
	popfd
	xor eax, ecx
	jz .error
	ret
.error:
	mov ebx, cpuid_error
	call print_string
	hlt

detect_long_mode:
	mov eax, 0x80000000
	cpuid
	cmp eax, 0x80000001
	jb .error
	mov eax, 0x80000001
	cpuid
	test edx, 1 << 29
	jz .error
	ret
.error:
	mov ebx, no_long_mode_error
	call print_string
	hlt

section .data
multiboot_error: db "ERROR IN MULTIBOOT",0
cpuid_error: db "ERROR: NO CPUID",0
no_long_mode_error: db "ERROR: LONG MODE NOT SUPPORTED",0
