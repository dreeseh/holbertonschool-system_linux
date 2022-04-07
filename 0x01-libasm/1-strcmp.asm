BITS 64

	global asm_strcmp

	section .text

asm_strcmp:
	push	rbp
	mov	rbp,	rsp
	push	rdx

loop:
	mov	dl,	[rdi]
	mov	dh,	[rsi]
	cmp	dl,	dh
	jl	lessthan
	jg 	greaterthan
	cmp	dl,	0h
	je 	check
	inc	rdi
	inc	rsi
	jmp	loop

lessthan:
	mov	eax,	-1h
	jmp	out

greaterthan:
	mov	eax,	1h
	jmp	out

check:
	mov	eax,	0h

out:
	pop	rdx
	mov	rsp,	rbp
	pop	rbp
	ret