



section .rodata
	msg db "Addition is :%f",10,0

section .data
	arr1:dq 1.1,2.2,3.1,9.0
	arr2:dq 1.2,2.3,3.2,3.4
	
section .text
	global main
	extern printf

main:	movups xmm0,[arr1]

	 movups xmm1,[arr2]
	addps xmm1,xmm0

	sub rsp,8
	movups xmm0,xmm1
	mov rdi,msg
	mov rax,1
	call printf
	add rsp,8
	
	
