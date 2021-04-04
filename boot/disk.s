extern PROGRAM_SPACE
;PROGRAM_SPACE equ 0x10000

read_disk:
	mov ah, 0x02		;read disk
	mov bx, PROGRAM_SPACE
	mov al, 64		;sectors
	mov dl, [BOOT_DISK]
	mov ch, 0x00		;cylinder 0
	mov dh, 0x00		;head 0
	mov cl, 0x02		;second sector

	int 0x13


	jc disk_read_error

	ret

BOOT_DISK:
	db 0

disk_read_fail_message:
	db "FAILD TO READ DISK",0

disk_read_error:
	mov bx, disk_read_fail_message
	call print_string
	jmp $
