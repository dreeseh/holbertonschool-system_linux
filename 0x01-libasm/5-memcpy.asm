	BITS 64

	global asm_memcpy

	section .text

asm_memcpy:
	push	rbp
	mov	rbp,	rsp
	push	rbx

loop:
	test	rdx,	rdx
	jz	out
	mov	bl,	[rsi]
	mov	[rdi],	bl
	inc	rdi
	inc	rsi
	dec	rdx
	jmp	loop

out:
	pop	rbx
	mov	rsp,	rbp
	pop	rbp
	ret