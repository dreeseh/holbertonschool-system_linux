	BITS 64

	global asm_puti
	extern asm_putc

	section .text

asm_puti:
	push	rbp
	mov 	rbp,	rsp
	push	r15
 	push	r14
	push	r13

	xor	r15,	r15
	xor	r14,	r14
	movsx	r15,	edi
	xor	rax,	rax

	cmp	r15,	0
	jge	zero
	imul	r15,	-1
	mov	r13,	1
	mov	rdi,	45

	call	asm_putc

zero:
	test	r15,	r15
	jnz	loop
	mov	rdi,	48
	call	asm_putc
	mov	r13,	1

loop:
	xor	rdx,	rdx
	test	r15,	r15
	jz	done_loop
	mov	rax,	r15
	mov	rbx,	10
	div	rbx

	mov	r15,	rax

after_div:
	push	rdx

after_push:
	inc	r14
	jmp	loop

done_loop:
	mov	r15,	r14

print:
	test	r15,	r15
	jz	done_print

	pop	rdi

after_pop:
	add	rdi,	48
	call asm_putc

	dec	r15
	jmp	print

done_print:
	cmp	r13,	1
	jne	out

	inc	r14

out:
	mov	rax,	r14
	pop	r13
	pop	r14
	pop	r15
	mov	rsp,	rbp
	pop rbp
	ret