init_id_paging:
	mov eax, page_table_l3
	or eax, 0b11
	mov [page_table_l4], eax

	mov eax, page_table_l2
	or eax, 0b11
	mov [page_table_l3], eax

	mov ecx, 0

.loop:					;set each page with huge mode
	mov eax, 0x200000
	mul ecx
	or eax, 0b10000011
	mov [page_table_l2 + ecx * 8], eax
	inc ecx
	cmp ecx, 512
	jne .loop

	ret

enable_paging:
	mov eax, page_table_l4
	mov cr3, eax

	mov eax, cr4			;enable PAE
	or eax, 1 << 5
	mov cr4, eax

	mov ecx, 0xc0000080		;enable long mode
	rdmsr
	or eax, 1 << 8
	wrmsr

	mov eax, cr0			;enable paging
	or eax, 1 << 31
	mov cr0, eax

	ret

	
