%macro qincbin 2
	section .rodata
	global %1
%1:
	incbin %2
	db 0
	%1_size: dq %1_size - %1
%endmacro

qincbin TEst, "./misc/test.txt"
qincbin minfo, "./misc/minfo.txt"

