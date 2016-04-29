section .rodata
		star db "* ",0
		space db " ",0
		newline db "",10,0
		msg db "Enter the numbers:",10,0		
		fmt db "%d",0
		
section .bss
	num resq 1
	num1 resq 1
	
section .text
		global main
		extern printf,scanf
	
main:
		mov rdi,msg 
		xor rax,rax
		call printf
		
		mov rdi,fmt
		mov rsi,num
		xor rax,rax
		call scanf
		
		xor r8,r8
		xor r9,r9
		xor r10,r10
		xor r11,r11
		xor r12,r12
		mov r15,[num]
		mov rbx,1
		mov r14,1
		xor r13,r13
		


loop:	cmp r15,0
		je end
		mov r12,r15
		
loop1:	
		cmp r12,0
		je loop2
		
		mov rdi,space
		xor rax,rax
		call printf
		
		dec r12
		jmp loop1


loop2:
		cmp r13,r14
		je loop3
		
		mov rdi,star
		mov rax,0
		call printf
		
		mov rdi,space
		mov rax,0
		call printf
		
		inc r13
		jmp loop2
		
		
		
loop3: 	mov rdi,newline
		xor rax,rax
		call printf
		
		inc r14
		
		dec r15
		
		xor r13,13
		jmp loop
		
end:ret
		

