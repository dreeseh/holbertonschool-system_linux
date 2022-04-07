BITS 64
	global asm_strcmp
	section .text

asm_strcmp
	push rbp
	mov rbp, rsp
	push rdx

	xor rcx, rcx

.L5:
        mov     rax, QWORD PTR [rbp-8]
        movzx   edx, BYTE PTR [rax]
        mov     rax, QWORD PTR [rbp-16]
        movzx   eax, BYTE PTR [rax]
        cmp     dl, al
        jne     .L7
        add     QWORD PTR [rbp-8], 1
        add     QWORD PTR [rbp-16], 1
.L2:
        mov     rax, QWORD PTR [rbp-8]
        movzx   eax, BYTE PTR [rax]
        test    al, al
        jne     .L5
        jmp     .L4
.L7:
        nop
.L4:
        mov     rax, QWORD PTR [rbp-8]
        movzx   eax, BYTE PTR [rax]
        movzx   edx, al
        mov     rax, QWORD PTR [rbp-16]
        movzx   eax, BYTE PTR [rax]
        movzx   eax, al
        sub     edx, eax
        mov     eax, edx
        pop     rbp
        ret