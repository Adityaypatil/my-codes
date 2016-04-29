section .rodata
	msg db "Numbeer is found",10,0
	msg1 db "Number is not found",10,0
	
	
section .data

	array dq 10,20,30,40,50,-1
	no dq 60
	
section .text
	global main
	extern printf,scanf

main: 	mov rbx,array
	mov rax,qword[no]

lp1:	cmp qword[rbx],-1
	je exit

	cmp qword[rbx],rax
	je f
	add rbx,8
	jmp lp1

f:	xor rax,rax
	mov rsi,rbx
	mov rdi,msg
	call printf

nf:
	xor rax,rax
	mov rdi,msg1
	call printf
	
exit:
	ret
