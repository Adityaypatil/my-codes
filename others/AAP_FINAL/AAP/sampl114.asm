section .rodta
	 msg db "minumum is :%d",10,0

section .data
	array dq 10,20,30,40,50,-1

section .text
       global main
       extern printf

main:
     xor rsi,rsi
     xor rcx,rcx
     mov rsi,[array+rcx*8]
     inc rcx
l:   mov rbx,[array+rcx*8]
     cmp rbx,-1
     je last
     inc rcx
     mov rdx,rbx
     cmp rsi,rdx
     jg gr
     jmp l
gr:	mov rsi,rdx
	jmp l

	
last: xor rax,rax
      mov rdi,msg
      call printf

        ret
	
