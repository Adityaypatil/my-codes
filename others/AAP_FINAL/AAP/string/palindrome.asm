section .rodata
	        msg db "%c",0

section .data
	        stri db "aditya",10,0

section .text
	        global main
	        extern printf

main:
	        xor rsi,rsi
	        xor rdi,rdi
	        xor rdx,rdx
	        mov r9,stri

lp:
	        cmp qword[r9],0
	        je lp1
	        inc r9
	        inc rdx
	        jmp lp

lp1:
	        cmp rdx,-1
	        je end

	        push r9
	        push rdx
	        mov rdi,msg
	        mov rsi,qword[r9]
	        xor rax,rax
	        call printf
	        pop rdx
	        pop r9

	        dec r9
	        dec rdx
		jmp lp1
end:	
