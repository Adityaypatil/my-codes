%macro pri 1
	push rax
	mov rdi,%1
	xor rax,rax
	call printf
	pop rax
%endmacro

%macro sys 1
	push rax
	mov rdi,%1
	xor rax,rax
	call system
	pop rax
%endmacro
		
section .rodata
	msg2 db "*",0
	clr db "clear",0
	msg db "sleep 0.09",0
		
section .data
	n dq 10	
	nl db 10,0

section .text
	global main
	extern printf,scanf,system

main:	
	enter 0,0
	mov rbx,qword[n]
	mov r10,0

lll:	
	cmp r10,1
	je fff
ll:	
	cmp rbx,0
	je end
	sys msg
	pri msg2
	pri nl
	dec rbx
	jmp ll

end:
	sys clr
	inc r10
	mov rbx,qword[n]
		
	jmp lll

fff:
	leave
	ret	
