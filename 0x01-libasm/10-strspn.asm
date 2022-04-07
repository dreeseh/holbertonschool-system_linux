	BITS 64

	global	asm_strspn

	section .text

asm_strspn:
	push	rbp
	mov	rbp,	rsp
	push	rbx
	push	rcx
	push	r11
	mov	rcx, 	0
	mov	r11,	0

loop:
	cmp	byte [rdi + rcx],	0
	je	out
	mov	rbx,	0

loop_2:
	mov	r11b, [rsi + rbx]
	cmp	r11b,	0
	je	out
	inc	rbx
	cmp	r11b, [rdi + rcx]
	jne	loop_2
	inc	rcx
	jmp	loop

out:
	mov	rax,	rcx
	pop	r11
	pop	rcx
	pop	rbx
	mov	rsp,	rbp
	pop	rbp
	ret