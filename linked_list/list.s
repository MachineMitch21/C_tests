	.file	"list.c"
	.section .rdata,"dr"
LC0:
	.ascii "list.c\0"
LC1:
	.ascii "list != NULL\0"
	.text
	.globl	_list_new
	.def	_list_new;	.scl	2;	.type	32;	.endef
_list_new:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$8, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L2
	movl	$11, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L2:
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.globl	_list_size
	.def	_list_size;	.scl	2;	.type	32;	.endef
_list_size:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jne	L4
	movl	$19, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L4:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L5
L6:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L5:
	cmpl	$0, -12(%ebp)
	jne	L6
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_list_is_empty
	.def	_list_is_empty;	.scl	2;	.type	32;	.endef
_list_is_empty:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.globl	_list_get_element
	.def	_list_get_element;	.scl	2;	.type	32;	.endef
_list_get_element:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jne	L11
	movl	$40, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L11:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	testl	%eax, %eax
	jne	L12
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L13
L16:
	movl	-16(%ebp), %eax
	cmpl	12(%ebp), %eax
	jne	L14
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	jmp	L15
L14:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L13:
	cmpl	$0, -12(%ebp)
	jne	L16
L12:
	movl	8(%ebp), %eax
	movl	$-1, 4(%eax)
	movl	$0, %eax
L15:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.section .rdata,"dr"
LC2:
	.ascii "node != NULL && list != NULL\0"
	.text
	.globl	_list_push
	.def	_list_push;	.scl	2;	.type	32;	.endef
_list_push:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 12(%ebp)
	je	L18
	cmpl	$0, 8(%ebp)
	jne	L19
L18:
	movl	$71, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	__assert
L19:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	testl	%eax, %eax
	je	L20
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	$1, %eax
	jmp	L21
L20:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	$1, %eax
L21:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.globl	_list_pop
	.def	_list_pop;	.scl	2;	.type	32;	.endef
_list_pop:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jne	L23
	movl	$91, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L23:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free_node
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.globl	_list_peek
	.def	_list_peek;	.scl	2;	.type	32;	.endef
_list_peek:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L25
	movl	8(%ebp), %eax
	movl	$-3, 4(%eax)
	movl	$0, %eax
	jmp	L26
L25:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
L26:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.globl	_list_push_back
	.def	_list_push_back;	.scl	2;	.type	32;	.endef
_list_push_back:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 12(%ebp)
	je	L28
	cmpl	$0, 8(%ebp)
	jne	L29
L28:
	movl	$112, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	__assert
L29:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L30
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L34
L30:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L32
L33:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
L32:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L33
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
L34:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.globl	_list_pop_back
	.def	_list_pop_back;	.scl	2;	.type	32;	.endef
_list_pop_back:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jne	L36
	movl	$133, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L36:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L37
	movl	8(%ebp), %eax
	movl	$-2, 4(%eax)
	jmp	L43
L37:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_size
	cmpl	$1, %eax
	jne	L39
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	jmp	L40
L39:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L41
L42:
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
L41:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L42
	movl	-16(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free_node
L40:
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
L43:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.globl	_list_peek_back
	.def	_list_peek_back;	.scl	2;	.type	32;	.endef
_list_peek_back:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jne	L45
	movl	$165, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L45:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L46
	movl	8(%ebp), %eax
	movl	$-3, 4(%eax)
	movl	$0, %eax
	jmp	L47
L46:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L48
L49:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
L48:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L49
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
L47:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.globl	_list_clear
	.def	_list_clear;	.scl	2;	.type	32;	.endef
_list_clear:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L52
	movl	$188, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L53:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_pop
L52:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	testl	%eax, %eax
	je	L53
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.globl	_free_list
	.def	_free_list;	.scl	2;	.type	32;	.endef
_free_list:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L55
	movl	$198, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L55:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_clear
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	__assert;	.scl	2;	.type	32;	.endef
	.def	_free_node;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
