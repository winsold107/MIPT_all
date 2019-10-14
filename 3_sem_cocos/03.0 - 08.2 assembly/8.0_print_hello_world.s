#print hello world

	.intel_syntax noprefix
	.global _start
	.text

_start:

	mov eax, 4
	mov ebx, 1
	mov ecx, s_ptr
	mov edx, 14
	
	int 0x80
	
	mov eax, 1
	int 0x80
	
.data

s:	
	.string "Hello, World!\n"
s_ptr: 
	.ptr brk	
