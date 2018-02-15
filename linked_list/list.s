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
	movl	$18, 8(%esp)
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
	movl	$39, 8(%esp)
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
L15:
	movl	-16(%ebp), %eax
	cmpl	12(%ebp), %eax
	jne	L13
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	jmp	L14
L13:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L15
L12:
	movl	8(%ebp), %eax
	movl	$-1, 4(%eax)
	movl	$0, %eax
L14:
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
	je	L17
	cmpl	$0, 8(%ebp)
	jne	L18
L17:
	movl	$68, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	__assert
L18:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	testl	%eax, %eax
	je	L19
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	$1, %eax
	jmp	L20
L19:
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
L20:
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
	jne	L22
	movl	$88, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L22:
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
	jne	L24
	movl	8(%ebp), %eax
	movl	$-3, 4(%eax)
	movl	$0, %eax
	jmp	L25
L24:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
L25:
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
	je	L27
	cmpl	$0, 8(%ebp)
	jne	L28
L27:
	movl	$109, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	__assert
L28:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L29
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L33
L29:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L31
L32:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
L31:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L32
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
L33:
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
	jne	L35
	movl	$130, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L35:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L36
	movl	8(%ebp), %eax
	movl	$-2, 4(%eax)
	jmp	L42
L36:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_size
	cmpl	$1, %eax
	jne	L38
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	jmp	L39
L38:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L40
L41:
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
L40:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L41
	movl	-16(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free_node
L39:
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
L42:
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
	jne	L44
	movl	$162, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L44:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L45
	movl	8(%ebp), %eax
	movl	$-3, 4(%eax)
	movl	$0, %eax
	jmp	L46
L45:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L47
L48:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
L47:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L48
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
L46:
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
	jne	L51
	movl	$185, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L52:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_pop
L51:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	testl	%eax, %eax
	je	L52
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.section .rdata,"dr"
LC3:
	.ascii "list != NULL && node != NULL\0"
	.text
	.globl	_list_insert
	.def	_list_insert;	.scl	2;	.type	32;	.endef
_list_insert:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	je	L54
	cmpl	$0, 12(%ebp)
	jne	L55
L54:
	movl	$195, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC3, (%esp)
	call	__assert
L55:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L56
	cmpl	$0, 16(%ebp)
	je	L56
	movl	8(%ebp), %eax
	movl	$-1, 4(%eax)
	jmp	L53
L56:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L58
	cmpl	$0, 16(%ebp)
	jne	L58
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L53
L58:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
L62:
	movl	16(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jne	L59
	cmpl	$0, -16(%ebp)
	je	L60
	movl	-16(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L61
L60:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
L61:
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	jmp	L53
L59:
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	addl	$1, -20(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L62
	movl	8(%ebp), %eax
	movl	$-1, 4(%eax)
	nop
L53:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.globl	_list_remove
	.def	_list_remove;	.scl	2;	.type	32;	.endef
_list_remove:
LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	cmpl	$0, 8(%ebp)
	jne	L64
	movl	$245, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L64:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_list_is_empty
	cmpl	$1, %eax
	jne	L65
	movl	8(%ebp), %eax
	movl	$-3, 4(%eax)
	jmp	L63
L65:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
L70:
	movl	12(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jne	L67
	cmpl	$0, -16(%ebp)
	je	L68
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	-16(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free_node
	jmp	L63
L68:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -32(%ebp)
	movl	8(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_free_node
	jmp	L63
L67:
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	addl	$1, -20(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L70
	movl	8(%ebp), %eax
	movl	$-1, 4(%eax)
	nop
L63:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE30:
	.globl	_free_list
	.def	_free_list;	.scl	2;	.type	32;	.endef
_free_list:
LFB31:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L72
	movl	$289, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L72:
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
LFE31:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	__assert;	.scl	2;	.type	32;	.endef
	.def	_free_node;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
