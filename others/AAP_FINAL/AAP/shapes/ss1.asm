section .data
	msg db "%d",0
	msg1 db " ",0
	msg2 db "  ",0
	msg3 db "*",0
	msg4 db "",10,0
section .bss
	n resd 1
	k resd 1
	m resd 1
	l resd 1
	f resd 1
	k2 resd 1
section .txt
	global main
	extern scanf
	extern printf
main:  enter 0,0
	xor eax,eax
	xor ebx,ebx
	xor ecx,ecx
	xor edx,edx
	mov dword[l],2
	div dword[l]
	mov dword[f],eax
	mov dword[k2],eax

	xor eax,eax

	pusha
	push n
	push msg
	call scanf
	add esp,8
	popa
	
	mov eax,dword[n]
	mov dword[m],eax
	mul dword[l]
	add dword[m],eax
	mov ebx,dword[n]
	mov edx,-1
	mov eax,dword[n]
        
	xor edx,edx

loop13:	cmp ecx,dword[n]
	je loop1

loop3:	cmp edx,ecx
	je loop2

	pusha
	push msg1
	call printf
	add esp,4
	popa
	add edx,1
	jmp loop3

loop2:	pusha
	push msg3
	call printf
	add esp,4
	popa

        xor eax,eax
	
	cmp dword[f],ecx 
	jbe loop4

loop6:	cmp eax,dword[f]
	je loop5
	pusha
	push msg1
	call printf
	add esp,4
	popa
	add eax,1
	jmp loop6

loop5:	pusha
		push msg3
		call printf
		add esp,4
		popa
		xor ebx,ebx
		mov dword[l],0
		mov ebx,dword[k2]
		sub ebx,eax
loop8:	cmp dword[l],ebx
		je loop7
	pusha
	push msg2
	call printf
	add esp,4
	popa
	add dword[l],1
	jmp loop8

loop7:	pusha
		push msg3
		call printf
		add esp,4
		popa
	xor eax,eax
	
loop9:	cmp eax,dword[f]
	je loop10
	pusha
	push msg1
	call printf
	add esp,4
	popa
	add eax,1
	jmp loop9
loop10:	pusha
	push msg3
	call printf
	add esp,4
	popa
	pusha
	push msg4
	call printf
	add esp,4
	popa
	add ecx,1
	jmp loop13
	
loop4: xor eax,eax
       mov eax,dword[m]	
       sub eax,ecx
	xor ebx,ebx
loop12:	cmp ebx,eax
	je loop11
	pusha
	push msg2
	call printf
	add esp,8
	popa
	add ebx,1
	jmp loop12
loop11:	pusha
	push msg3
	call printf
	add esp,4
	push msg4
	call printf
	add esp,4
	popa
	add ecx,1
	jmp loop13
loop1:	leave
	ret
