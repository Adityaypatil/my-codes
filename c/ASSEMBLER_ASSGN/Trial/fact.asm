section.data
	n1 db 5
section.text
main:	xor eax eax
	xor ebx ebx
	mov eax 1
	mov ebx n1
next:	mul eax ebx
	sub ebx 1
	jnz next
	sub eax [n1]
Exit:	ret

