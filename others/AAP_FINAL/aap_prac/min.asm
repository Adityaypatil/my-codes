section .rodata
	msg db "Minimum no is :%d",10,0

section .data
	x dq 1.1
	y dq 2.2

section .text
	global main
	extern printf

main:
	xor rsi,rsi

	movsd xmm0,[x]
	movsd xmm1,[y]
	minpd xmm0,xmm1

	mov rdi,msg
	call printf
