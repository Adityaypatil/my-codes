section .rodta
	 msg db "*",10,0

section .data
	n dq 5

section .text
	global main
	extern printf

main:	xor rax,rax
	
	mov rax,0
	mov rbx,0
	mov rax,n
	
lp1:	cmp rax,n
	ja exit

lp2:	cmp rbx,rax
	ja lp
	jmp print
	inc rbx
	jmp lp2

print:	xor rax,rax
	mov rdi,msg
	call printf
	
lp:	inc rax
	jmp lp1
	
exit:	ret
