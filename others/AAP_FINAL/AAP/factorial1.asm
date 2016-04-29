section .data
	msg db "consist %d",10,0
	msg4 db "addition %d",10,0
	msg1 db "first is %s",10,0
	msg2 db "second is %s",10,0
	msg3 db "third is %s",10,0
section .txt
	global main
	extern printf
	extern atoi
main:
	enter 0,0
	mov eax,dword[ebp+8]
	push eax
	push msg
	call printf
	add esp,8
	
	mov ebx,dword[ebp+12]
	push dword[ebx]
	push msg1
	call printf
	add esp,8
	
	mov ebx,dword[ebp+12]
	push dword[ebx+4]
	push msg2
	call printf
	add esp,8
	
	mov ebx,dword[ebp+12]
	cmp dword[ebx+8],(null)
	jz loop1
	jmp loop2
loop1:	mov ecx,8
	push ecx
	push msg
	call printf
	add esp,8
loop2:	leave
	ret