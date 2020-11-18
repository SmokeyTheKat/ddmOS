global switchTasks
extern func

switchTasks:
	push eax
	mov eax, esp
	mov esp, [esp + 8]
	push eax
	call func
	pop esp
	pop eax
	ret
