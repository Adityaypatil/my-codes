section .rodata
	msg db "Fact is: %d",10,0
	msg1 db "Enter no:",0
	no dq "%d",0
	
section .bss
	f resq 1
	
section .text
	global  main
	extern printf,scanf

main:
	mov rdi,msg1
	xor rax,rax
	call printf

	mov rdi,no
	mov rsi,f
	xor rax,rax
	call scanf

	mov rcx,qword[f]
	mov rax,1

lp1:	mul rcx
	loop lp1

	mov rdi,msg
	mov rsi,rax
	xor rax,rax
	call printf
	
	
