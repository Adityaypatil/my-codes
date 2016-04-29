section .data
	msg db "%d number of arguments",10,0
section .text
	global main
	extern puts,printf
main:

	push rdi
	push rsi
	sub rsp,8
	push rdi
	push rsi
	mov rsi,rdi
	mov rdi,msg
	xor rax,rax
	call printf
	pop rsi
	pop rdi
	mov rdi,[rsi]
	call puts
	add rsp,8
	pop rsi
	pop rdi
	add rsi,8
	dec rdi
	jnz main
	ret
