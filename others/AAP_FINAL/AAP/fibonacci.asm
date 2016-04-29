section .rodata
	msg db "Number:",10,0
	msg1 db "Fibonacci series:",10,0
	fmt db "%d"

section .bss
	n resq 1

section .text
	global main
	extern scanf,printf

main:
	xor rax,rax
	mov rdi,
