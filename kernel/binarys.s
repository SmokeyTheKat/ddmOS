%macro qincbin 2
	section .rodata
	global %1
%1:
	incbin %2
	db 0
	%1_size: dq %1_size - %1
%endmacro

;qincbin test, "test.txt"
qincbin minfo, "minfo.txt"

