strcmp:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-8], rdi
        mov     QWORD [rbp-16], rsi
        jmp     L2
L5:
        mov     rax, QWORD [rbp-8]
        movzx   edx, BYTE [rax]
        mov     rax, QWORD [rbp-16]
        movzx   eax, BYTE [rax]
        cmp     dl, al
        jne     L7
        add     QWORD [rbp-8], 1
        add     QWORD [rbp-16], 1
L2:
        mov     rax, QWORD [rbp-8]
        movzx   eax, BYTE [rax]
        test    al, al
        jne     L5
        jmp     L4
L7:
        nop
L4:
        mov     rax, QWORD [rbp-8]
        movzx   eax, BYTE [rax]
        movzx   edx, al
        mov     rax, QWORD [rbp-16]
        movzx   eax, BYTE [rax]
        movzx   eax, al
        sub     edx, eax
        mov     eax, edx
        pop     rbp
        ret