%macro pri 1
	push rax
	mov rdi,%1
	xor rax,rax
	call printf
	pop rax
%endmacro

section .rodata
	msg db "*",0
	msg11 db " ",0
	msg1 db 10,0
section .data
	r dq 4
	
section .text
	global main
	extern printf
	
main:	mov r9,qword[r]
		
		
lp:		cmp r9,0
		je end
		
		pri msg11
		dec r9
		jmp lp
		
		
end: pri msg
	pri msg1
	dec r9
	jmp lp
	
	ret
		
