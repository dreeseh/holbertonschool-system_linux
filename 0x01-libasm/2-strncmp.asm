	BITS 64

	global asm_strncmp

	section .text

asm_strncmp:
	push rbp
	mov rbp, rsp
	push rcx

	xor rcx, rcx

loop:
	cmp rcx, rdx
	je compare
	mov al, [rdi + rcx]
	mov bl, [rsi + rcx]
	test al, al
	jz compare
	test bl, bl
	jz compare
	cmp al, bl
	jne compare
	inc rcx
	jmp loop

compare:
	cmp al, bl
	je equal
	jl sub
	jg add

equal:
	mov rax, 0
	jmp out

sub:
	mov rax, -1
	jmp out

add:
	mov rax, 1
	jmp out

out:
	pop rcx
	mov rsp, rbp
	pop rbp
	ret