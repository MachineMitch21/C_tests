	.file	"test.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Test\0"
LC1:
	.ascii "Test 2\0"
LC2:
	.ascii "Test 3\0"
LC3:
	.ascii "The list has %d elements.\12\12\0"
LC4:
	.ascii "Element 0 data: %s\12\0"
LC5:
	.ascii "Element 1 data: %s\12\0"
LC6:
	.ascii "Element 2 data: %s\12\0"
	.align 4
LC7:
	.ascii "List has %d element after pop and pop_back.\12\0"
LC8:
	.ascii "Element 0 data: %s\12\12\0"
LC10:
	.ascii "Dummy struct double: %f\12\0"
LC11:
	.ascii "Dummy struct int: %d\12\0"
LC12:
	.ascii "Dummy struct string: %s\12\0"
	.align 4
LC13:
	.ascii "Dummy struct list now has %d elements.\12\0"
	.align 4
LC14:
	.ascii "Clear test list has %d elements.\12\0"
	.align 4
LC15:
	.ascii "Clear test list has %d elements after list_clear\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$96, %esp
	call	___main
	call	_list_new
	movl	%eax, 92(%esp)
	movl	$LC0, 88(%esp)
	movl	$4, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 84(%esp)
	movl	84(%esp), %eax
	movl	%eax, 4(%esp)
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$4, 4(%esp)
	movl	$LC1, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$4, 4(%esp)
	movl	$LC2, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_peek
	movl	%eax, 80(%esp)
	cmpl	$0, 80(%esp)
	je	L2
	movl	80(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
L2:
	movl	$1, 4(%esp)
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 76(%esp)
	cmpl	$0, 76(%esp)
	je	L3
	movl	76(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
L3:
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_peek_back
	movl	%eax, 72(%esp)
	cmpl	$0, 76(%esp)
	je	L4
	movl	72(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
L4:
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop_back
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	call	_list_new
	movl	%eax, 68(%esp)
	fldl	LC9
	fstpl	40(%esp)
	movl	$32, 48(%esp)
	movl	$LC0, 52(%esp)
	movl	$16, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 64(%esp)
	movl	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	68(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$0, 4(%esp)
	movl	68(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	(%eax), %edx
	movl	%edx, 24(%esp)
	movl	4(%eax), %edx
	movl	%edx, 28(%esp)
	movl	8(%eax), %edx
	movl	%edx, 32(%esp)
	movl	12(%eax), %eax
	movl	%eax, 36(%esp)
	fldl	24(%esp)
	fstpl	4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	32(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_printf
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	movl	68(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop
	movl	68(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
	call	_list_new
	movl	%eax, 60(%esp)
	movl	$8, 20(%esp)
	movl	$15, 16(%esp)
	movl	$4, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	$4, 4(%esp)
	leal	16(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC14, (%esp)
	call	_printf
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	_list_clear
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_free_list
	movl	68(%esp), %eax
	movl	%eax, (%esp)
	call	_free_list
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	_free_list
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.section .rdata,"dr"
	.align 8
LC9:
	.long	-1717986918
	.long	1074370969
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_list_new;	.scl	2;	.type	32;	.endef
	.def	_node_new;	.scl	2;	.type	32;	.endef
	.def	_list_push;	.scl	2;	.type	32;	.endef
	.def	_list_push_back;	.scl	2;	.type	32;	.endef
	.def	_list_size;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_list_peek;	.scl	2;	.type	32;	.endef
	.def	_list_get_element;	.scl	2;	.type	32;	.endef
	.def	_list_peek_back;	.scl	2;	.type	32;	.endef
	.def	_list_pop;	.scl	2;	.type	32;	.endef
	.def	_list_pop_back;	.scl	2;	.type	32;	.endef
	.def	_list_clear;	.scl	2;	.type	32;	.endef
	.def	_free_list;	.scl	2;	.type	32;	.endef
