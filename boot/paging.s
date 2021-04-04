page_table_entry equ 0x1000

init_id_paging:
	mov edi, page_table_entry
	mov cr3, edi			;set page start addr
	mov dword[edi], 0x2003		;addr of second table / flags
	add edi, 0x1000
	mov dword[edi], 0x3003
	add edi, 0x1000
	mov dword[edi], 0x4003
	add edi, 0x1000

	mov ebx, 0x00000003
	mov ecx, 512

.entry:
	mov dword[edi], ebx
	add ebx, 0x1000
	add edi, 8
	loop .entry

	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	mov ecx, 0xc0000080
	rdmsr
	or eax, 1 << 8
	wrmsr

	mov eax, cr0
	or eax, 1 << 31
	mov cr0, eax
	ret
