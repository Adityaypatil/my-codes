section .data
	msg db "Enter the length %d",10,0
	fmt dq "%d",10,0
	msg1 db "Enter the breadth %d",10,0
	fmt1 dq " %d",10,0

	star db " *",10,0
	spce db " ",0
	
section .bss
	l resq 1
	b resq 1
	
section .text
		global main
		extern printf,scanf
		
main:
		mov rdi, msg
		call printf
		
		
		
		
		
		
		ret
		
