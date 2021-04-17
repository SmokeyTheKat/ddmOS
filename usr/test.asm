[bits 64]
test_main:
	push rbp
	mov rbp, rsp
	mov rcx, 2
	mov r8, 500
	mov r9, 10000000
	int 0x69
	pop rbp
	ret
