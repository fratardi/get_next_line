	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_bufnpos
	.p2align	4, 0x90
_bufnpos:                               ## @bufnpos
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
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_get_next_line
	.p2align	4, 0x90
_get_next_line:                         ## @get_next_line
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movl	$6, %eax
	movl	%eax, %ecx
	leaq	-22(%rbp), %rdx
	leaq	L_.str(%rip), %r8
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%r8, _get_next_line.rez(%rip)
	movq	%rdx, %rdi
	movq	%rcx, %rsi
	callq	_ft_bzero
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	$5, %eax
	movl	%eax, %edx
	leaq	-22(%rbp), %rcx
	movl	-8(%rbp), %edi
	movq	%rcx, %rsi
	callq	_read
	cmpq	$0, %rax
	je	LBB1_3
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	leaq	-22(%rbp), %rsi
	movq	_get_next_line.rez(%rip), %rdi
	callq	_ft_strjoin
	movl	$6, %ecx
	movl	%ecx, %esi
	leaq	-22(%rbp), %rdi
	movq	%rax, _get_next_line.rez(%rip)
	callq	_ft_bzero
	jmp	LBB1_1
LBB1_3:
	movl	$10, %esi
	movq	_get_next_line.rez(%rip), %rdi
	callq	_ft_strchr
	movq	%rax, -32(%rbp)
	cmpq	$0, %rax
	je	LBB1_5
## BB#4:
	movq	-32(%rbp), %rdi
	callq	_ft_putendl
	movq	_get_next_line.rez(%rip), %rdi
	movq	_get_next_line.rez(%rip), %rax
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	callq	_ft_strlen
	movq	-32(%rbp), %rdi
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	callq	_ft_strlen
	movq	-48(%rbp), %rdi         ## 8-byte Reload
	subq	%rax, %rdi
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	%rdi, -56(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	-56(%rbp), %rsi         ## 8-byte Reload
	callq	_ft_strndup
	movq	-16(%rbp), %rsi
	movq	%rax, (%rsi)
	movq	-32(%rbp), %rdi
	callq	_ft_strdup
	movq	%rax, _get_next_line.rez(%rip)
	movq	_get_next_line.rez(%rip), %rdi
	callq	_ft_putendl
	movl	$1, -4(%rbp)
	jmp	LBB1_8
LBB1_5:
	cmpq	$0, -32(%rbp)
	jne	LBB1_7
## BB#6:
	movq	-32(%rbp), %rdi
	callq	_ft_strdup
	movq	-16(%rbp), %rdi
	movq	%rax, (%rdi)
LBB1_7:
	movl	$0, -4(%rbp)
LBB1_8:
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

.zerofill __DATA,__bss,_get_next_line.rez,8,3 ## @get_next_line.rez
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.space	1


.subsections_via_symbols
