	BITS 64

	global asm_puti_base

	extern asm_putc
	extern asm_strlen

	section .text

asm_puti_base:
	push	rbp
	mov	rbp,	rsp

	push	r12
	push	r13
	push	r14
	push	r15

	xor	rax,	rax
	xor	r14,	r14
	xor	r15,	r15
	movsx	r15,	edi
	cmp	r15,	0
	jge	negative

	imul	r15,	-1

	mov	r13,	1
	mov	rdi,	45

	push	rsi
	push	rbx
	call	asm_putc

	pop	rbx
	pop	rsi

negative:
	mov	rdi,	rsi
	call	asm_strlen
	mov	rbx,	rax
	cmp	rbx,	1
	jnz	zero
	mov	r14,	r15

one:
	test	r15,	r15
	jz	done_one
	xor	rax,	rax
	mov	al,	BYTE [rsi]
	push	rax
	dec	r15
	jmp	one

done_one:
	xor	rax,	rax
	jmp	loop

zero:
	test	r15,	r15
	jnz loop
	movzx	rdi,	BYTE [rsi]
	call	asm_putc
	mov	r13,	1

loop:
	test	rbx,	rbx
	jz	loop_nba
	xor	rdx,	rdx
	test	r15,	r15
	jz	done
	mov	rax,	r15
	div	rbx
	mov	r15,	rax
	xor	rax,	rax
	mov	al,	BYTE [rsi + rdx]
	push	rax
	inc	r14
	jmp	loop

done:
	jmp	loop_2

loop_nba:
	xor	rdx,	rdx
	test	r15,	r15
	jz	loop_nb
	mov	rax,	r15
	mov	rbx,	10
	div	rbx
	mov	r15,	rax
	xor	rax,	rax
	mov	rax,	rdx
	add	rax,	48
	push	rax
	inc	r14
	jmp	loop_nba

loop_nb:

loop_2:
	mov	r15,	r14

print:
	test	r15,	r15
	jz	done_loop
	pop	rdi

after_pop:
	call	asm_putc
	dec	r15
	jmp	print

done_loop:
	cmp	r13,	1
	jne	out
	inc	r14

out:
	mov	rax,	r14
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	mov	rsp,	rbp
	pop	rbp
	ret