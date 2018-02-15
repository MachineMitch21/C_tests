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
	.ascii "Test 4\0"
LC4:
	.ascii "The list has %d elements.\12\12\0"
LC5:
	.ascii "Element 0 data: %s\12\0"
LC6:
	.ascii "Element 1 data: %s\12\0"
LC7:
	.ascii "Element 2 data: %s\12\0"
LC8:
	.ascii "Element 3 data: %s\12\12\0"
	.align 4
LC9:
	.ascii "List has %d element after pop and pop_back.\12\0"
LC10:
	.ascii "Element 0 data: %s\12\12\0"
LC12:
	.ascii "Dummy struct double: %f\12\0"
LC13:
	.ascii "Dummy struct int: %d\12\0"
LC14:
	.ascii "Dummy struct string: %s\12\0"
	.align 4
LC15:
	.ascii "Dummy struct list now has %d elements.\12\0"
	.align 4
LC16:
	.ascii "Clear test list has %d elements.\12\0"
LC17:
	.ascii "\12Value 0: %d\12\12\0"
LC18:
	.ascii "Value 1: %d\12\12\0"
	.align 4
LC19:
	.ascii "Clear test has %d elements after removing index 0\12\0"
	.align 4
LC20:
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
	subl	$112, %esp
	call	___main
	call	_list_new
	movl	%eax, 108(%esp)
	movl	$LC0, 104(%esp)
	movl	$4, 4(%esp)
	movl	104(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 100(%esp)
	movl	100(%esp), %eax
	movl	%eax, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$4, 4(%esp)
	movl	$LC1, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$4, 4(%esp)
	movl	$LC2, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_node_new
	movl	$1, 8(%esp)
	movl	%eax, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_insert
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 96(%esp)
	cmpl	$0, 96(%esp)
	je	L2
	movl	96(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
L2:
	movl	$1, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 92(%esp)
	cmpl	$0, 92(%esp)
	je	L3
	movl	92(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
L3:
	movl	$2, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 88(%esp)
	cmpl	$0, 92(%esp)
	je	L4
	movl	88(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
L4:
	movl	$4, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 84(%esp)
	cmpl	$0, 84(%esp)
	je	L5
	movl	84(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
L5:
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop_back
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	call	_list_new
	movl	%eax, 80(%esp)
	fldl	LC11
	fstpl	48(%esp)
	movl	$32, 56(%esp)
	movl	$LC0, 60(%esp)
	movl	$16, 4(%esp)
	leal	48(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 76(%esp)
	movl	76(%esp), %eax
	movl	%eax, 4(%esp)
	movl	80(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$0, 4(%esp)
	movl	80(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	(%eax), %edx
	movl	%edx, 32(%esp)
	movl	4(%eax), %edx
	movl	%edx, 36(%esp)
	movl	8(%eax), %edx
	movl	%edx, 40(%esp)
	movl	12(%eax), %eax
	movl	%eax, 44(%esp)
	fldl	32(%esp)
	fstpl	4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	movl	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC14, (%esp)
	call	_printf
	movl	80(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop
	movl	80(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	call	_list_new
	movl	%eax, 72(%esp)
	movl	$8, 28(%esp)
	movl	$15, 24(%esp)
	movl	$4, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	$4, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, 68(%esp)
	movl	$1, 4(%esp)
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, 64(%esp)
	movl	68(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC17, (%esp)
	call	_printf
	movl	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC18, (%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_remove
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_clear
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC20, (%esp)
	call	_printf
	movl	108(%esp), %eax
	movl	%eax, (%esp)
	call	_free_list
	movl	80(%esp), %eax
	movl	%eax, (%esp)
	call	_free_list
	movl	72(%esp), %eax
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
LC11:
	.long	-1717986918
	.long	1074370969
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_list_new;	.scl	2;	.type	32;	.endef
	.def	_node_new;	.scl	2;	.type	32;	.endef
	.def	_list_push;	.scl	2;	.type	32;	.endef
	.def	_list_push_back;	.scl	2;	.type	32;	.endef
	.def	_list_insert;	.scl	2;	.type	32;	.endef
	.def	_list_size;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_list_get_element;	.scl	2;	.type	32;	.endef
	.def	_list_pop;	.scl	2;	.type	32;	.endef
	.def	_list_pop_back;	.scl	2;	.type	32;	.endef
	.def	_list_remove;	.scl	2;	.type	32;	.endef
	.def	_list_clear;	.scl	2;	.type	32;	.endef
	.def	_free_list;	.scl	2;	.type	32;	.endef
