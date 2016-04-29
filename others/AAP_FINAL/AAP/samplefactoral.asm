section .rodata
	msg1 db "Enter num:",10,0
	msg2 db "Factorial of num is:%d",10,0
	fmt db "%d"

section .bss
	a resq 1


	
section .text
	global main
	extern scanf,printf

main:	xor rax,rax
	mov rdi,msg1
	call printf

	mov rax,rax
	mov rdi,fmt
	mov rsi,n
	call scanf

	mov rcx,rsi
	mov rax,1
l1:	mul rcx
	loop l1

	mov rsi,rax
	mov rdi,msg2
	xor rax,rax
	call printf

	ret
