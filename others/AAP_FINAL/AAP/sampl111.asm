section .rodata
	msg db "hello world",10,0

section .text
	global main
	extern printf

main:	mov rdi,msg
	xor rax,rax
	call printf
