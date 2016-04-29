section .data
	msg2 db "\n",10,0
	msg3 db "%d",10,0
	msg db " * "
	msg1 db "   "
	
	
section .bss
	k resd 1
	j resd 1
	n resd 1
section .txt
	global main
	extern printf
	extern scanf

main:   xor eax,eax
	xor ebx,ebx
	xor ecx,ecx
	xor edx,edx
	mov dword[k],0
	mov dword[j],1

	 push n
	 push msg3
	 call scanf
	 add esp,8

	mov edx,dword[n]
	sub edx,1
	mov eax,dword[k]
	mov ebx,dword[j]


	
loop6:	cmp eax,dword[n]
	jnl loop3
	pusha
	push msg
	call printf
	add esp,4
	popa
	
loop2:	cmp ebx,edx
	jnl loop6
	cmp eax,0
	jne loop1
	pusha
	push msg
	call printf
	add esp,4
	popa
	add ebx,1
	jmp loop5
	
loop1: 	cmp eax,edx
	jne loop4
	pusha
	push msg
	call printf
	add esp,4
	popa
	add ebx,1
	jmp loop2

loop4:  pusha
	push msg1
	call printf
	add esp,4
	popa
loop5:
	push msg
	call printf
	add esp,4
	push msg1
	call printf
	add esp,4
	popa
	jmp loop6

loop3:	ret
	
