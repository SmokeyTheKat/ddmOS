global mmap_region_count
mmap_region_count:
	db 0

detect_memory:
	mov ax, 0
	mov es, ax
	mov di, 0x5000
	mov edx, 0x534d4150
	xor ebx, ebx
.loop
	mov eax, 0xe820
	mov ecx, 24
	int 0x15
	cmp ebx, 0
	je .done
	add di, 24
	inc byte[mmap_region_count]
	jmp .loop
.done
	ret
