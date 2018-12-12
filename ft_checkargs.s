	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_ft_checkargs
	.p2align	4, 0x90
_ft_checkargs:                          ## @ft_checkargs
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
	subq	$16, %rsp
	movl	%edi, -8(%rbp)
	cmpl	$1, -8(%rbp)
	jg	LBB0_2
## BB#1:
	leaq	L_.str(%rip), %rdi
	callq	_ft_putendl
	movl	$0, -4(%rbp)
	jmp	LBB0_5
LBB0_2:
	cmpl	$2, -8(%rbp)
	jle	LBB0_4
## BB#3:
	leaq	L_.str.1(%rip), %rdi
	callq	_ft_putendl
	movl	$0, -4(%rbp)
	jmp	LBB0_5
LBB0_4:
	movl	$1, -4(%rbp)
LBB0_5:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"File name is missing."

L_.str.1:                               ## @.str.1
	.asciz	"Too many arguments."


.subsections_via_symbols
