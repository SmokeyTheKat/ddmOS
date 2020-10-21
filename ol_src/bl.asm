BITS 16

init:
	jmp short start

data:
	yo db 'YO WHAT IS UP GAMERSSSSSSS', 0

start:
	mov bx, 000Fh
	
	mov ax, 07C0h
	add ax, 20h
	mov ss, ax
	mov sp, 4096

	mov ax, 07C0h
	mov ds, ax

	mov si, yo
	call print
	cli
	hlt





print:
	mov ah, 0Eh

.printchar:
	lodsb
	cmp al, 0
	je .done
	int 10h
	jmp .printchar
.done:
	ret


times 510-($-$$) db 0
dw 0xAA55
