section .data
	a db 10

section .bss
	c resq 1

section .text
	global main
	extern printf

main:
	mov rax,10
	mov rax,200
	mov rax,1000
	mov rax,10000
	mov rax,100000
