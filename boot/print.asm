[bits 32]
print_string:
	mov ecx, 0xb8000
.loop:
	mov ah, byte[ebx]
	cmp ah, byte 0
	je .exit
	mov byte[ecx], ah
	add ecx, 2
	add ebx, 1
	jmp .loop
.exit:
	ret
