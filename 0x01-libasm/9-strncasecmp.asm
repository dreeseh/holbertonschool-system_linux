	BITS 64

	global	asm_strncasecmp

	section	.text

asm_strncasecmp:
	push 	rbp
	mov	rbp,	rsp
	push 	r8
	push	r9
	push	rcx
	xor	rcx,	rcx
	xor	eax,	eax
	xor	r8d,	r8d
	xor	r9d,	r9d

loop:
	mov	r8b,	BYTE [rdi + rcx]
	mov	r9b,	BYTE [rsi + rcx]
	cmp	r8b,	65
	jl	check
	cmp	r8b,	90
	jg	check
	add	r8b,	32

check:
	cmp	r9b,	65
	jl	cont
	cmp	r9b,	90
	jg	cont
	add	r9b,	32

cont:
	test	r8b,	r8b
	je	out
	test	r9b,	r9b
	je	out
	inc	rcx
	cmp	rcx,	rdx
	je	out
	cmp	r8b,	r9b
	je	loop
	jmp	out

out:
	mov	eax,	r8d
	sub	eax,	r9d
	pop	rcx
	pop	r9
	pop	r8
	mov	rsp,	rbp
	pop	rbp
	ret