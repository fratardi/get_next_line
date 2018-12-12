	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, -64(%rbp)
	movl	$0, -60(%rbp)
	movq	$0, -32(%rbp)
	movl	-8(%rbp), %edi
	callq	_ft_checkargs
	cmpl	$0, %eax
	jne	LBB0_2
## BB#1:
	movl	$0, -4(%rbp)
	jmp	LBB0_3
LBB0_2:
	xorl	%esi, %esi
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	movb	$0, %al
	callq	_open
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %edi
	movq	-32(%rbp), %rsi
	callq	_get_next_line
	movl	$0, -4(%rbp)
	movl	%eax, -68(%rbp)         ## 4-byte Spill
LBB0_3:
	movl	-4(%rbp), %eax
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
