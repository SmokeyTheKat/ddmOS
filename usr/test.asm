[bits 64]
_start:
	push rbp
	mov rbp, rsp
	mov rcx, 2
	mov r8, 500
	mov r9, 40000000
	int 0x69
	mov rcx, 0
	mov rcx, 2
	mov r8, 200
	mov r9, 10000000
	int 0x69
	int 0x69
	int 0x69
	int 0x69
	int 0x69
	int 0x69
	int 0x69
	int 0x69
	int 0x69
	mov byte[test_str+0x600], byte 'b'
	mov byte[test_str+0x601], byte 'y'
	mov rcx, 0
	mov r8, test_str
	mov r9, test_str_end-test_str
	int 0x69
	pop rbp
	ret

test_str:
	db "hi there omg yo :D",0
test_str_end:
