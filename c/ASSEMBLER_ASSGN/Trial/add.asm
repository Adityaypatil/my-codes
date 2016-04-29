
section.data
	n1 db 10
section.text
       
main:	mov n2 [n1]
	mov ebx 05
next:	xor eax eax	
	add eax ebx
	jc  next
           
Exit:	ret
n2 db 200
