section .rodata
	msg db "hello world",10,0
	len equ $-msg
section .text
	global main

	
main:	mov rax,1
	mov rdi,1
	mov rsi,msg
	mov rdx,len
	syscall
