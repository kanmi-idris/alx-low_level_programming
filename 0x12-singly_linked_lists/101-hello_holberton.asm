section .data
    msg db 'Hello, Holberton', 0Ah, 0

section .text
    global main

main:
    ; write(1, msg, 17)
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, 17
    syscall

    ; exit(0)
    mov rax, 60
    xor rdi, rdi
    syscall
    