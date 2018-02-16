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
LC19:
	.ascii "List error code: %d\12\12\0"
	.align 4
LC20:
	.ascii "Clear test has %d elements after removing with remove_i and remove_n\12\0"
	.align 4
LC21:
	.ascii "Clear test list has %d elements after list_clear\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	addl	$-128, %esp
	call	___main
	call	_list_new
	movl	%eax, 124(%esp)
	movl	$LC0, 120(%esp)
	movl	$4, 4(%esp)
	movl	120(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 116(%esp)
	movl	116(%esp), %eax
	movl	%eax, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$4, 4(%esp)
	movl	$LC1, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$4, 4(%esp)
	movl	$LC2, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_node_new
	movl	$1, 8(%esp)
	movl	%eax, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_insert
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 112(%esp)
	cmpl	$0, 112(%esp)
	je	L2
	movl	112(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
L2:
	movl	$1, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 108(%esp)
	cmpl	$0, 108(%esp)
	je	L3
	movl	108(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
L3:
	movl	$2, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 104(%esp)
	cmpl	$0, 108(%esp)
	je	L4
	movl	104(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
L4:
	movl	$4, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 100(%esp)
	cmpl	$0, 100(%esp)
	je	L5
	movl	100(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
L5:
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop_back
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	call	_list_new
	movl	%eax, 96(%esp)
	fldl	LC11
	fstpl	56(%esp)
	movl	$32, 64(%esp)
	movl	$LC0, 68(%esp)
	movl	$16, 4(%esp)
	leal	56(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 92(%esp)
	movl	92(%esp), %eax
	movl	%eax, 4(%esp)
	movl	96(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push
	movl	$0, 4(%esp)
	movl	96(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	(%eax), %edx
	movl	%edx, 40(%esp)
	movl	4(%eax), %edx
	movl	%edx, 44(%esp)
	movl	8(%eax), %edx
	movl	%edx, 48(%esp)
	movl	12(%eax), %eax
	movl	%eax, 52(%esp)
	fldl	40(%esp)
	fstpl	4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	movl	48(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
	movl	52(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC14, (%esp)
	call	_printf
	movl	96(%esp), %eax
	movl	%eax, (%esp)
	call	_list_pop
	movl	96(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	call	_list_new
	movl	%eax, 88(%esp)
	movl	$8, 36(%esp)
	movl	$15, 32(%esp)
	movl	$4, 4(%esp)
	leal	36(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	$4, 4(%esp)
	leal	32(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_push_back
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, 84(%esp)
	movl	$1, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	4(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, 80(%esp)
	movl	84(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC17, (%esp)
	call	_printf
	movl	80(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC18, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_get_element
	movl	%eax, 76(%esp)
	movl	$15, 28(%esp)
	movl	$4, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_node_new
	movl	%eax, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_remove_n
	testl	%eax, %eax
	jne	L6
	movl	88(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
L6:
	movl	$0, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_remove_i
	movl	76(%esp), %eax
	movl	%eax, 4(%esp)
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_remove_n
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC20, (%esp)
	call	_printf
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_clear
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_list_size
	movl	%eax, 4(%esp)
	movl	$LC21, (%esp)
	call	_printf
	movl	124(%esp), %eax
	movl	%eax, (%esp)
	call	_free_list
	movl	96(%esp), %eax
	movl	%eax, (%esp)
	call	_free_list
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_free_list
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
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
	.def	_list_remove_n;	.scl	2;	.type	32;	.endef
	.def	_list_remove_i;	.scl	2;	.type	32;	.endef
	.def	_list_clear;	.scl	2;	.type	32;	.endef
	.def	_free_list;	.scl	2;	.type	32;	.endef
