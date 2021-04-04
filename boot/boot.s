[bits 16]
global _start
_start:
	mov [BOOT_DISK], dl	;get disk number

	mov bp, 0x7c00		;move stack to top of prgram
	mov sp, bp

	call read_disk

	jmp PROGRAM_SPACE

%include "boot/print.s"
%include "boot/disk.s"

times 510-($-$$) db 0
dw 0xaa55
