section .rodata
	a dq 4.10
	b dq 4.40

	msg db "Addition is:%f ",10,0
section .bss
	q resq 1

section .text
	global main
	extern printf
main:
	movq xmm0,qword[a]
	movq xmm1,qword[b]

	addsd xmm0,xmm1

	movq [q],xmm0

	movq xmm0,qword[q]
	sub rsp,8
	mov rdi,msg
	mov rax,1
	call printf
	add rsp,8
