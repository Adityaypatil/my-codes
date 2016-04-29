section .data
	a dd 10
	
section .bss
	b resd 1
section .text
main:
	mov eax ,10
	mov eax,ebx
	
add:	call printf
	add esp,8
	mov eax,eax
