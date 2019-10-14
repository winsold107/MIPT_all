//сумму двух целых десятичных чисел

.text
.data
.global main

main:
	// r8 scanf, r9 printf
	push {r4, r5, r6, r7, r8, r9, lr}
	
	ldr r8, format_string_scanf_ptr
	ldr r9, format_string_printf_ptr
	
	// memory on stack
	sub sp, #8
	
	// args and call scanf
	mov r0, r8
	mov r1, sp
	mov r2, sp
	add r2, #4
	bl scanf
	
	// calculate
	ldr r4, [sp]
	ldr r5, [sp, #4]
	add r4, r5
	
	// args and call printf
	mov r1, r4
	mov r0, r9
	bl printf
	
	add sp, #8
	pop {r4, r5, r6, r7, r8, r9, lr}
	
	// ending
	bx lr
	
format_string_printf_ptr:
	.word format_string_printf
format_string_scanf_ptr:
	.word format_string_scanf

	.section .rodata
format_string_printf:
	.ascii "%d\n\0"
format_string_scanf:
	.ascii "%d%d\0"


//qemu-arm -L ~/github/MIPT/3_sem_cocos/3/sysroot "./%e"
//~/github/MIPT/3_sem_cocos/3/sysroot/bin/arm-linux-gnueabi-gcc %f temp.c -o %e -marm
