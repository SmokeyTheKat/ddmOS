[bits 64]
section .text
global long_mode_start
long_mode_start:
	mov ax, 0
	mov ss, ax
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	extern kmain
	call kmain

	hlt
