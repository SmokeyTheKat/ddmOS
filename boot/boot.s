section .boot ; start sequence from linker
bits 16 ; 16 bit mode
global boot
boot:
	mov ax, 0x2401 ; 
	int 0x15 ; enable a20 line

	mov ax, 0x3 ; mode 3
	int 0x10 ; vga text mode 3

	mov [disk], dl ; disk from bios

	mov ah, 0x2 ; read avaible sectors
	mov al, 6 ; sectors to load
	mov ch, 0 ; index
	mov dh, 0 ; head 
	mov cl, 2 ; sector
	mov dl, [disk] ; disk number from bios
	mov bx, copy_target; ; target
	int 0x13 ; 
	cli

	lgdt [gdt_pointer] ; gets gdt table pointer
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
	

start_gdt:
	dq 0x0
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
end_gdt:
gdt_pointer:
	dw end_gdt - start_gdt
	dd start_gdt
disk:
	db 0x0
CODE_SEG equ gdt_code - start_gdt
DATA_SEG equ gdt_data - start_gdt


times 510 - ($-$$) db 0 ; padding for the 510 bytes
dw 0xaa55 ; when bios sees this is says it is bootable


copy_target:
bits 32
;	more: db "Here is more text past the 512 byte mark yoooo!",0

bootr:
;	mov esi, more
;	mov ebx, 0xb8000
;
;.loop:                     ; print loop
;	lodsb
;	or al, al ; if al == 0
;	jz halt ; then end as msg is null termainting
;	or eax, 0x0F00
;	mov word [ebx], ax
;	add ebx, 2
;	jmp .loop
;halt:
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
