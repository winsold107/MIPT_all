//x86 (IA-32) программу, которая копирует содержимое со стандартного потока ввода на стандартный поток вывода

#include <asm/unistd_32.h>
	.intel_syntax noprefix
	.global _start    
	.text

_start:
	push ebp
	mov ebp, esp

loopRead:	
	mov eax, __NR_read #номер read
	mov ebx, 0 #stdin
	mov edx, 80 #размер
	lea ecx, [esp] #указатель
	int 0x80 #системный вызов Linux
	
	mov esi, eax

	mov   eax, __NR_write  #номер write
    mov   ebx, 1  #файловый дескриптор stdout
    lea   ecx, [esp]
    mov   edx, esi  #количество байт в выводе
    int   0x80	
	
	cmp esi, 80
	je loopRead
	
	pop ebp
	
	mov ebx, __NR_exit
	mov eax, 1
	int 0x80
	
