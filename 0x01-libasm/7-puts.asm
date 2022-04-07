	BITS 64
	
	global	asm_puts

	extern	asm_strlen

	section	.text

asm_puts:
	push	rbp
	mov	rbp,	rsp
	push	rdi

	call	asm_strlen
	pop	rdi

	push	rdi
	push    rsi
	mov     rdx,	rax
	mov     rax,	1
	mov     rsi,	rdi
	mov     rdi,	1
	syscall

	pop     rsi
	pop     rdi
	mov     rsp,	rbp
	pop     rbp
	ret