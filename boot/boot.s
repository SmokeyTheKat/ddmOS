section .boot ; start sequence from linker
bits 16 ; 16 bit mode
global boot
boot:
	mov ax, 0x2401 ; 
	int 0x15 ; enable a20 line

	mov ax, 0x13 ; mode 3
	int 0x10 ; vga text mode 3

	mov [disk], dl ; disk from bios

	mov ah, 0x2 ; read avaible sectors
	mov al, 64 ; sectors to load
	mov ch, 0 ; index
	mov dh, 0 ; head 
	mov cl, 2 ; sector
	mov dl, [disk] ; disk number from bios
	mov bx, copy_target; ; target
	int 0x13 ; 
	cli

	lgdt [gdt_descr] ; gets gdt table pointer
	sti ; enable interrupts
	mov eax, cr0 ; load reg cr0
	or eax, 0x1 ; set protected move bit on reg cr0
	mov cr0, eax

	mov ax, DATA_SEG
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

	jmp CODE_SEG:bootr ; goto code
	
	

gdt_start:
	dd 0x0
	dd 0x0
gdt_code:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10011010b
	db 11001111b
	db 0x0
gdt_data:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0
gdt_end:
gdt_descr:
	dw (gdt_end - gdt_start) + 1
	dd gdt_start
disk:
	db 0x0
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start


times 510 - ($-$$) db 0 ; padding for the 510 bytes
dw 0xaa55 ; when bios sees this is says it is bootable


copy_target:
bits 32

bootr:
	mov esp, kstack_top
	extern kmain ; load kernal main function
	call kmain ; run kernal main function
	cli ; clear interupt flag
	hlt ; stop


section .bss
align 4
kstack_bottom: equ $ 
	resb 16384 ; reserve 16 kb for stack
kstack_top:
