section .rodta
	msg db "Sum if num :%d",10,0

section .data
	array dq 10,20,30,40,50,-1

section .text
	global main
	extern printf

main:
	xor rsi,rsi
	xor rcx,rcx
l:	mov rbx,[array+rcx*8]
	cmp rbx,-1
	je last
	inc rcx
	add rsi,rbx
	jmp l
last:	xor rax,rax
	mov rdi,msg
	call printf


	ret
