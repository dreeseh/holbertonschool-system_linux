	BITS 64

	global asm_strchr

	section .text

asm_strchr:
	push rbp
	mov rbp, rsp

	xor rax, rax

loop:
	mov al, [rdi]
	cmp al , sil
	je match
	test al, al
	jz null
	inc rdi
	jmp loop

null:
	xor rax, rax
	jmp out

match:
	mov rax, rdi

out:
	mov rsp, rbp
	pop rbp
	ret