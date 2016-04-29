	.file	"test1.c"
	.globl	data1
	.data
	.align 4
	.type	data1, @object
	.size	data1, 4
data1:
	.long	10
	.globl	data2
	.align 4
	.type	data2, @object
	.size	data2, 4
data2:
	.long	20
	.comm	result,4,4
	.section	.rodata
.LC0:
	.string	"Result is %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	movl	data1, %eax
	movl	data2, %ecx
	movl	%eax, %edx
#APP
# 7 "test1.c" 1
	imull %edx,%ecx
	movl %ecx,%eax
# 0 "" 2
#NO_APP
	movl	%eax, result
	movl	result, %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
