#Функция вычисляет значения Ri=Ai+Bi для всех i от 0 до N.

#Память для хранения массива-результата уже выделена.

	.global summ
	.intel_syntax noprefix
	.text
summ:
	# Prologue
	
	push ebp
	# summ args == ebp+8(N), ebp+12(A), ebp+16(B), ebp+20(R), ...
	mov ebp, esp
	
	
	push ecx
	mov ecx, [ebp+8]
	
.Loop:
	# ebx == current i == ecx-1
	mov ebx, ecx
	dec ebx # ebx--
		
	# A
	mov eax, [ebp+12]
	# A[i]
	mov eax, [eax + 4*ebx]
	# R[i] = A[i]
	mov edx, eax
	
	# B
	mov eax, [ebp+16]
	# B[i]
	mov eax, [eax + 4*ebx]
	# R[i] = R[i] + B[i]
	add edx, eax
	
	mov eax, [ebp+20]
	mov [eax + 4*ebx], edx
	
	loop .Loop

	pop ecx

	# Epilogue
	pop ebp
	ret
