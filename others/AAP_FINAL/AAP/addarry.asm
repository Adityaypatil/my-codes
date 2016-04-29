section .data
	msg dd 1.2,2.1,3.1,4.1
	msg1 dd 9,1,1,1

section .text
	global main

main:
	movups xmm0,[msg]
	movups xmm1,[msg1]

	addpd xmm0,xmm1

	ret
