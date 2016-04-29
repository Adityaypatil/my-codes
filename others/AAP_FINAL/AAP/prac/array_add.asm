section .rodata
	msg db "Addition of array is :%d",10,0

section .data
	array dq 10,10,10,30,-1

section .text
	global main
	extern printf
main:
	xor rcx,rcx
	xor rsi,rsi
loop:	mov rbx,[array+rcx*8]
	cmp rbx,-1
	je last
	inc rcx
	add rsi,rbx
	jmp loop

last:	xor rax,rax
	mov rdi,msg
	call printf
