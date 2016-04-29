section .rodata
	msg db "Addision is :%f",10,0

section .data
	x dq 1.2
	y dq 1.3

section .bss
	c resq 1
section .text
	global main
	extern printf

main:
	movq xmm0,qword[x]
	movq xmm1,qword[y]

	addsd xmm0,xmm1
	 movq [c],xmm0

	sub rsp,8
	movq xmm0,qword[c]
	mov rdi,msg
	mov rax,1
	call printf
	add rsp,8
