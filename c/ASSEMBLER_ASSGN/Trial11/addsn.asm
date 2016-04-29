section .data
	msg db "Addision is %d",10,0
	a dd 10

section .text
	global main
	extern printf

main:	xor eax,eax
	xor ecx,ecx

	mov eax,dword[a]

lp:	add ecx,eax
	dec eax
	jz lp1
	jmp lp

lp1:	push ecx
	push msg
	call printf
	add esp,8
	ret
	
	
