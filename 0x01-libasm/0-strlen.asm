global	strlen
	; int strlen(const char *string);
strlen:
	push	edi
	sub	ecx, ecx
	mov	edi, [esp+8]
	not	ecx
	sub	al, al
	cld
repne	scasb
	not	ecx
	pop	edi
	lea	eax, [ecx-1]
	ret