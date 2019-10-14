#Первая функция вычисляет значение выражения (A+B)/(C+D) и возвращает результат. Можно использовать #как вычисления с помощью i387 FPU, так и с помощью инструкций SSE.

#Вторая функция вычисляет поэлементную сумму R[i]=A[i]+B[i]. Гарантируется, что число N больше нуля и #кратно 4, а адреса массивов выровнены в памяти по границе 32 байта. Используйте векторные инструкции #для вычисления.

	.intel_syntax noprefix
	.text
	.global calc
calc:
	push ebp
	mov ebp, esp
	fld qword ptr [ebp+16]
	fadd qword ptr [ebp+8]
	fild dword ptr [ebp+32]
	fadd qword ptr [ebp+24]
	pop ebp
	fdivp st(1), st
	ret


	.global vector_sum
vector_sum:
		push ebp
		push esi
		push edi
		push ebx
		mov ebp, esp
		mov ecx, [ebp+20]
		mov esi, [ebp+24]
		mov edi, [ebp+28]
		mov ebx, [ebp+32]
		mov eax, 0
Loop:
		movaps xmm0, [esi+eax*4]
		movaps xmm1, [edi+eax*4]
		addps xmm0, xmm1
		movaps [ebx+eax*4], xmm0
		add eax, 4
		cmp eax, ecx
		jl Loop
		pop ebx
		pop edi
		pop esi
		pop ebp
		ret
