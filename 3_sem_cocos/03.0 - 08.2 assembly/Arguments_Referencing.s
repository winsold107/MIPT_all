	.global summ
	.intel_syntax noprefix
	.text
summ:
	# Prologue
	
	push ebp
	# summ args == ebp+8, ebp+12, ...
	mov ebp, esp
	

	# printf args

	# pushing arg3
	mov ecx, [esp+12]
	push ecx
	# pushing arg2
	mov ecx, [ebp+8]
	push ecx
	# pushing arg1
	mov ecx, offset printf_format_string
	push ecx
	
	call printf
	
	pop ecx
	pop ecx
	pop ecx
	
	
	pop ebp
	ret
	
	
printf_format_string:
	.string "Hello world![%d][%d]\n"


