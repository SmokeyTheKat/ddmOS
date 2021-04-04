gdt_null_dscr:
	dd 0
	dd 0
gdt_code_dscr:
	dw 0xFFFF	;limit
	dw 0x0000	;low base
	db 0x00		;mid base
	db 0b10011010	;flags
	db 0b11001111	;flags / upper limit
	db 0x00		;high base
gdt_data_dscr:
	dw 0xFFFF	;limit
	dw 0x0000	;low base
	db 0x00		;mid base
	db 0b10010010	;flags
	db 0b11001111	;flags / upper
	db 0x00		;hight base
gdt_end:
	
gdt_dscr:
	gdt_size:
		dw gdt_end - gdt_null_dscr - 1
		dq gdt_null_dscr

codeseg equ gdt_code_dscr - gdt_null_dscr
dataseg equ gdt_data_dscr - gdt_null_dscr

[bits 32]

edit_gdt: 		; for 64 bit access
	mov [gdt_code_dscr + 6], byte 0b10101111
	mov [gdt_data_dscr + 6], byte 0b10101111
	ret

[bits 16]
