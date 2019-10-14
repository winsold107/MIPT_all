#Первая функция вычисляет значения Ri=Ai+Bi для всех i от 0 до N.

#Вторая функция:

#вводит с клавиатуры знаковое целое число;
#умножает его на X;
#прибавляет к нему Y;
#выводит результат на экран.


	.global summ
	.intel_syntax noprefix
	.text
summ:
	# Prologue
	push ebx
	
	mov ecx, N
.Loop:
	# R[N-1] = A[N-1] + B[N-1]
	mov ebx, ecx
	dec ebx # ebx = N-1
	
	mov edx, A
	mov eax, [edx + 4*ebx]
	mov edx, B
	add eax, [edx + 4*ebx] # += B[N-1]
	mov edx, R
	mov [edx + 4*ebx], eax # R[N-1] = %eax
	loop .Loop # if (ecx==0) { goto next instr; } else { ecx--; goto .Loop }

	# Epilogue
	pop ebx
	ret
	
	.global everyday795
everyday795:
	# prologue
	push ebp
	mov ebp, esp
	push ebx
	
	# сдвинем стек для хранения временной переменной и аргументов scanf
	sub esp, 4 # for local temp variable
	sub esp, 8 # for scanf arguments
	
	# &Temp = esp+8
	mov eax, esp # сохраняем stack
	add eax, 8 # сдвигаем стек на 8 - scanf args
	
	# Заполнение аргументов scanf
	mov [esp+4], eax # копируем во временную перем значение на верх стека
	mov ecx, offset scanf_format_string # кладем в ecx строку scanf
	mov [esp+0], ecx # кладем на верх стека scanf format string 
	call scanf # вызываем scanf
	
	# кладем в ebx 
	mov ebx, [esp+8]
	imul ebx, [ebp+8]
	add ebx, [ebp+12]
	mov ecx, printf_format_string_ptr
	mov [esp+0], ecx
	mov [esp+4], ebx
	call printf
	
	add esp, 8
	
	# epilogue
	add esp, 4
	pop ebx
	pop ebp
	ret
	
scanf_format_string:
	.string "%d"
printf_format_string_ptr:
	.long printf_format_string
	
	.data
printf_format_string:
	.string "%d\n"

