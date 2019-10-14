	.file	"8.0.c"
	.section	.rodata
.LC0:
	.string	"asdf"
	.data
	.align 8
	.type	ptr1, @object
	.size	ptr1, 8
ptr1:
	.quad	.LC0
	.section	.rodata
.LC1:
	.string	"q"
	.data
	.align 8
	.type	ptr2, @object
	.size	ptr2, 8
ptr2:
	.quad	.LC1
	.section	.rodata
.LC2:
	.string	"Hello\n"
	.data
	.align 8
	.type	str, @object
	.size	str, 8
str:
	.quad	.LC2
	.section	.rodata
.LC3:
	.string	"%s,%d,%c\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	ptr2(%rip), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %ecx
	movq	ptr1(%rip), %rax
	movl	(%rax), %edx
	movq	str(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
