%macro pri 1
	push rax
	mov rdi,%1
	xor rax,rax
	call printf
	pop rax
%endmacro

section .rodata
	msg db "*",0
	msg1 db 10,0
section .data
	r dq 4
	c dq 4
	
section .text
	global main
	extern printf
	
main:	mov r9,qword[r]
		mov rdx,qword[c]
		
lp:		cmp r9,0
		je exit
		
lp1:		cmp rdx,0
		je end
		
		pri msg
				
		dec rdx
		jmp lp1
			
end:		pri msg1	
				
		dec r9
		
		mov rdx,qword[c]
		
		jmp lp
		
			
exit:	ret	
