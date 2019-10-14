#x86 (IA-32) программу, которая читает со стандартного потока ввода текст, после чего выводит все #строки текста в обратном порядке.	

#include <asm/unistd_32.h>

.intel_syntax noprefix
	.global _start    
	.text

_start:
	push ebp
	push esi
	push edi
	mov ebp, esp

	
	mov eax, __NR_brk
	mov ebx, 0
	int 0x80
	
	mov edi, eax
	push edi
	mov esi, edi
	add esi, 4096
	
	mov eax, __NR_brk
	mov ebx, esi
	int 0x80
	
loopRead:	
	mov eax, __NR_read	 		 #номер read
	mov ebx, 0			 #stdin
	mov edx, 4096 		 #размер
	mov ecx, edi		 #указатель
	# lea ecx, [edi]
	int 0x80 			 #системный вызов Linux
	add esi, eax
	add edi, eax
	
	cmp eax, 0
	jz preLoopCompare
	
	mov    eax, __NR_brk               #system call brk
    mov    ebx, esi 
    int    0x80
	
	jmp loopRead
	
preLoopCompare: 
	mov esi, 0
	mov edx, [ebp - 4]
	
loopCompare:
	dec edi 
	cmp edi, edx
	jl end
	mov al, byte ptr [edi]
	cmp al, 0x0A
	
	jz loopWrite
	inc esi
	
	jmp loopCompare
	
loopWrite:
	mov   eax, __NR_write  #номер write
    mov   ebx, 1  #файловый дескриптор stdout
    lea   ecx, [edi + 1]
    mov   edx, esi  #количество байт в выводе
    int   0x80
    
    mov eax, __NR_write
    mov ebx, 1
    mov ecx, s_ptr
    mov edx, 1
    int 0x80
    
    jmp preLoopCompare
    
end:  
	mov   eax, __NR_write  #номер write
    mov   ebx, 1  #файловый дескриптор stdout
    lea ecx, [edi + 1]
    mov   edx, esi  #количество байт в выводе
    int   0x80
    
    
    pop edi
    pop esi
	pop ebp
	
	mov ebx, __NR_exit
	mov eax, 1
	int 0x80

.data
s:	
	.string "\n"
s_ptr: 
	.long s
