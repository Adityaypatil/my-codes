section .rodata
	msg db "hello pucsd",10,0
	msg2 db "lenghth of string is: %d ",10,0
	
section .text
	global main
	extern printf

main:	xor rsi,rsi
	xor rcx,rcx

	mov rsi,msg
	
l:	cmp byte[rsi],0
	je last
	inc rsi
	inc rcx
	jmp l
	
last:	mov rsi,rcx
	mov rdi,msg2
	xor rax,rax
	call printf

	
	
	
