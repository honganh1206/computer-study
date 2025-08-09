	.file	"locality.c"
	.text
	.globl	averageMat_v1
	.type	averageMat_v1, @function
averageMat_v1:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L2
.L5:
	movl	$0, -8(%rbp)
	jmp	.L3
.L4:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	addl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L3:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L4
	addl	$1, -12(%rbp)
.L2:
	movl	-12(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L5
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-4(%rbp), %xmm0
	movl	-28(%rbp), %eax
	imull	%eax, %eax
	pxor	%xmm1, %xmm1
	cvtsi2ssl	%eax, %xmm1
	divss	%xmm1, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	averageMat_v1, .-averageMat_v1
	.globl	averageMat_v2
	.type	averageMat_v2, @function
averageMat_v2:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L8
.L11:
	movl	$0, -8(%rbp)
	jmp	.L9
.L10:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-12(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	addl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L9:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L10
	addl	$1, -12(%rbp)
.L8:
	movl	-12(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L11
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-4(%rbp), %xmm0
	movl	-28(%rbp), %eax
	imull	%eax, %eax
	pxor	%xmm1, %xmm1
	cvtsi2ssl	%eax, %xmm1
	divss	%xmm1, %xmm0
	cvttss2sil	%xmm0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	averageMat_v2, .-averageMat_v2
	.globl	initArr
	.type	initArr, @function
initArr:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L14
.L17:
	movl	$0, -4(%rbp)
	jmp	.L15
.L16:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %ecx
	movl	-4(%rbp), %edx
	addl	%ecx, %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L15:
	movl	-4(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L16
	addl	$1, -8(%rbp)
.L14:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L17
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	initArr, .-initArr
	.section	.rodata
.LC0:
	.string	"Average is: %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -24(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L19
.L20:
	movl	-32(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	$12, %edi
	call	malloc@PLT
	movq	%rax, (%rbx)
	addl	$1, -32(%rbp)
.L19:
	cmpl	$2, -32(%rbp)
	jle	.L20
	movq	-24(%rbp), %rax
	movl	$3, %edx
	movl	$3, %esi
	movq	%rax, %rdi
	call	initArr
	movq	-24(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	averageMat_v1
	movd	%xmm0, %eax
	movl	%eax, -28(%rbp)
	pxor	%xmm1, %xmm1
	cvtss2sd	-28(%rbp), %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	$0, -24(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
