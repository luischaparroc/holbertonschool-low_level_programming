section .data
	msg db "Hello, Holberton",10

	section .text
	global main

main:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, 17
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
