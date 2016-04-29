section .data
	fmt1 db "Enter the length",10,0
	fmt db "%d"
	fmt2 db "Enter the breadth",10,0
	fmt3 db "%d"
	string db "* ",0
	string2 db "  ",0
	msg1 db "%s",10,0
	
section .bss
	cnt resd 1
	string1 resd 20
	cnt1 resd 1
	n resd 1
	count resd 1

section .text
	global main
	extern printf,scanf

main:	enter 0,0
	xor edx,edx
	xor eax,eax
	xor ebx,ebx
	
	push fmt1
	call printf
	add esp,4
	
	push cnt
	push fmt
	call scanf
	add esp,8
	
	push fmt2
	call printf
	add esp,4
	
	push cnt1
	push fmt3
	call scanf
	add esp,8
	mov ecx,dword[cnt]
	add ecx,dword[cnt]
	mov dword[n],ecx
	xor ecx,ecx

	cmp dword[cnt],0
	jnz lp
	jmp end
	
lp:	cmp dword[cnt],1
	jne first
	mov esi,string
	mov edi,string1
	mov ecx,dword[cnt]
	cld
	lodsw
	rep stosw
	mov eax,4
	mov ebx,1
	mov ecx,string1
	mov edx,dword[n]
	int 0x80	
	jmp end

first:	pusha
	mov esi,string
	mov edi,string1
	mov ecx,dword[cnt]
	cld
	lodsw
	rep stosw
	mov eax,4
	mov ebx,1
	mov ecx,string1
	mov edx,dword[n]
	int 0x80	
	popa
	
	push string2
	push msg1
	call printf
	add esp,8
	
	mov ecx,dword[cnt1]
	sub ecx,2
	mov dword[count],ecx
mid:	xor eax,eax
	xor ebx,ebx
	xor ecx,ecx
	xor edx,edx
	pusha
	mov eax,4
	mov ebx,1
	mov ecx,string
	mov edx,1
	int 0x80	
	popa
	mov edx,dword[n]
	sub edx,3
	mov dword[cnt1],edx
	pusha
	mov esi,string2
	mov edi,string1
	mov ecx,dword[cnt]
	cld
	lodsw
	rep stosw
	mov eax,4
	mov ebx,1
	mov ecx,string1
	mov edx,dword[cnt1]
	int 0x80	
	popa
	
	pusha
	mov eax,4
	mov ebx,1
	mov ecx,string
	mov edx,1
	int 0x80	
	popa

	push string2
	push msg1
	call printf
	add esp,8

	dec dword[count]
	cmp dword[count],0
	jnz mid
last:	pusha
 	mov esi,string
	mov edi,string1
	mov ecx,dword[cnt]
	cld
	lodsw
	rep stosw
	mov eax,4
	mov ebx,1
	mov ecx,string1
	mov edx,dword[n]
	int 0x80	
	popa
	
	push string2
	push msg1
	call printf
	add esp,8

end:	leave
	ret
