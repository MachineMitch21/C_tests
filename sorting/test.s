	.file	"test.c"
	.section .rdata,"dr"
LC0:
	.ascii "%d \0"
	.text
	.globl	_print_array
	.def	_print_array;	.scl	2;	.type	32;	.endef
_print_array:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L2
L3:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	addl	$1, -12(%ebp)
L2:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L3
	movl	$10, (%esp)
	call	_putchar
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Unsorted array is \0"
LC2:
	.ascii "\12\12%d:%d:%d\12\12\0"
LC3:
	.ascii "\12Sorted array\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$400000000, (%esp)
	call	_malloc
	movl	%eax, 40(%esp)
	movl	$0, 44(%esp)
	jmp	L5
L6:
	movl	44(%esp), %eax
	leal	0(,%eax,4), %edx
	movl	40(%esp), %eax
	addl	%eax, %edx
	movl	$100000000, %eax
	subl	44(%esp), %eax
	movl	%eax, (%edx)
	addl	$1, 44(%esp)
L5:
	cmpl	$99999999, 44(%esp)
	jle	L6
	movl	$1, 36(%esp)
	movl	$LC1, (%esp)
	call	_puts
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_time
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_localtime
	movl	%eax, 32(%esp)
	movl	32(%esp), %eax
	movl	(%eax), %ecx
	movl	32(%esp), %eax
	movl	4(%eax), %edx
	movl	32(%esp), %eax
	movl	8(%eax), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	36(%esp), %eax
	subl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	_merge_sort
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_time
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_localtime
	movl	%eax, 32(%esp)
	movl	32(%esp), %eax
	movl	(%eax), %ecx
	movl	32(%esp), %eax
	movl	4(%eax), %edx
	movl	32(%esp), %eax
	movl	8(%eax), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$LC3, (%esp)
	call	_puts
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	_print_array
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_localtime;	.scl	2;	.type	32;	.endef
	.def	_merge_sort;	.scl	2;	.type	32;	.endef
