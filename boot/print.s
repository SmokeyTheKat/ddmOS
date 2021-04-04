[bits 16]
print_string:
	.loop:
	cmp [bx], word 0
	je .loop_end
	mov ah, 0x0e
	mov al, [bx]
	int 0x10
	inc bx
	jmp .loop
	.loop_end:
	ret
