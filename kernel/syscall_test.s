global syscall_test
syscall_test:
	mov rcx, 0
	mov rdi, sct_str
	mov rsi, 20
	int 0x80
	mov rcx, 1
	mov rdi, 50
	mov rsi, 10000000
	int 0x80
	ret

sct_str: db `syscall test string\n`,0
