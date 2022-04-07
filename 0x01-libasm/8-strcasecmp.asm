	BITS 64

	global	asm_strcasecmp

	section	.text

asm_strcasecmp:
	push	rbp
	mov	rbp,	rsp
	push	rcx
	push	r8
	push	r9

	xor	rcx,	rcx
	xor	r8,	r8
	xor	r9,	r9
	xor	eax,	eax

loop:
	mov	r8b,	[rdi + rcx]
	mov	r9b,	[rsi + rcx]
	cmp	r8b,	65
	jl	check
	cmp	r8b,	90
	jg	check
	add	r8b,	32

check:
	cmp	r9b,	65
	jl	count
	cmp	r9b,	90
	jg	count
	add	r9b,	32

count:
	mov	eax,	r8d
	sub	eax,	r9d
	test	eax,	eax
	jnz	out
	test	r8b,	r8b
	jz	out
	inc	rcx
	jmp	loop

out:
	pop	r9
	pop	r8
	pop	rcx
	mov	rsp,	rbp
	pop	rbp
	ret