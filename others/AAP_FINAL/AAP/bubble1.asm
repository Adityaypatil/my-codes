section .data
	fmt db "The sum of %d",10,0
	fmt2 db "%d"
	fmt1 db "The number %d",10,0
section .bss
	a resd 10
	num resd 1
section .text
	global main
	extern printf,scanf
main:
	push num
	push fmt2
	call scanf
	add esp,8
	xor edx,0
	mov eax,a
	xor ecx,ecx
for: 
	pusha
	mov eax,4
	mul ecx
	mov ebx,eax
	mov eax,a
	Add eax,ebx
	push eax
	push fmt2
        call scanf
	add esp,8
	popa
	inc ecx
	cmp ecx,dword[num]
	jne for
        leave
	
	ret
	