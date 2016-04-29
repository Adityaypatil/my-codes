section .rodata

	msg db "Enter any number:",10,0
	fmt dq "%d",10,0
	spce db " ",0
	newline db "",10,0
	star db "*",0
	
section .bss
	number resq 1

section .text
	global main
	extern scanf,printf

	
	
main:	mov rdi,msg
	xor rax,rax
	call printf

	mov rdi,fmt
	mov rsi,number
	xor rax,rax
	call scanf

	mov r8,[number]
	mov r9,r8

loop:	mov r8,[number]

loop1:	cmp r8,0
	 je loop2

	mov rdi,star
	mov rax,0
	call printf

	 mov rdi,spce
	 mov rax,0
	 call printf

	dec r8
	jmp loop1

 loop2:	 mov rdi,newline
	 mov rax,0
	call printf

loop3:	cmp r9,1
	je loop4

	dec r9
	jmp loop

loop4:	
	mov rdi,newline
	mov rax,0
	call printf
	ret
