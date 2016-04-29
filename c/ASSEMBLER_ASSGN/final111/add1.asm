section .data
	a dd 10
	
section .bss
	b resd 1
section .text
	global main
	extern printf
main:
	mov eax ,10
	mov eax,ebx
	call printf

add:	add esp,8
