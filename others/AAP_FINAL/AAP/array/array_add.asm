section .rodata
	msg db "Addition of array is : %d",10,0

section .data
	array dq 10,20,30,40,50,-1

section .text
	global main
	extern printf
	
main:   xor rcx,rcx
	mov rbx,array

lp1:	cmp qword[rbx],-1
	je exit
	add rcx,qword[rbx]
	add rbx,8
	jmp lp1

exit:	xor rax,rax
	mov rsi,rcx
	mov rdi,msg
	call printf
