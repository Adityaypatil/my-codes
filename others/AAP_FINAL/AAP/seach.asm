section .rodata
	msg db " no to be search:%d",10,0
	msg2 db "No is found",10,0
	msg3 db "No not found",10,0
	
section .data
	msg1 dq 10,20,30,40,50,60,-1
	no dd 30
	
section .text
	global main
	extern printf

main: 
	xor rcx,rcx
	
	mov rdx,msg1
	xor rcx,rcx
lp:	cmp qword[rdx+rcx*8],-1
        je end

	mov rbx,qword[rdx+rcx*8]
	cmp qword[no],rbx
	je last
	inc rcx
	jmp lp
	
	
last:	
	mov rdi,msg2
	xor rax,rax
	call printf
	ret

	
end:	
	mov rdi,msg3
	xor rax,rax
	call printf
        ret
