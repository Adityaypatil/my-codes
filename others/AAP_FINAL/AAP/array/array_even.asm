section .rodata
	msg  db "Even numbers from array: %d",10,0
	msg1 db "Odd numbers from array: %d",10,0

section .data

	array dq 10,20,30,40,-1

section .text
	global  main
	extern printf

main:   mov rbx,2
	mov rax,array

lp1:	cmp qword[rax],-1
	je exit

	div rbx
	cmp rdx,0
	je even
	add rax,8
	jmp lp1
	
even:	xor rax,rax
	mov rsi,rax
	mov rdi,msg
	call printf

exit:	ret
