%macro add_macro 2
	mov eax,%1
	add eax,%2

%endmacro

section .data
	msg db "Sum is :%d",10,0

section .text
	global main
	extern printf

main:
	add_macro 10,10
	push eax
	push msg
	call printf
	add esp,8
	
