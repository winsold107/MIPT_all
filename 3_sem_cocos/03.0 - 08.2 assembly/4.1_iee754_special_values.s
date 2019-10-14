//классифицирует специальные значения вещественного числа, на которое указывает value_ptr, в 
//cоответствии со стандартом IEEE 754.

.text
.global classify


classify:
	push {r4, r5, r6, r7, r8, r9, r10, r11}
	
		//считывание
	
	ldr r2, [r0]
	ldr r1, [r0, #4]
	
		//выделение масок для вычислений
	
	mov r4, #0x80000000 //константа знаковый бит маска
	// Sign ---> r4
	
	mov r5, #0x7f000000
	orr r5, r5, #0x00f00000 //константа экспонента маска
	// Exp ---> r5
	
	mov r6, #0xff000000
	orr r6, r6, #0x00f00000
	mvn r6, r6 //константа мантисса 1 кусок маска
	// Mant R1 ---> r6
	
		// выделения самих частей числа через маски

	// Sign
	and r7, r1, r4 //побитово сложила получила знак
	// Exp
	and r8, r1, r5 //получила экспоненту
	// Mant part1
	and r9, r1, r6 //получила 1 кусок мантиссы
	// Mant part2
	and r10, r2, #0xffffffff // получила второй кусок мантиссы
	
		//сравнение с константами
	b Constants

Constants:

PlusZero:
	cmp r7, #0
	bne SkipZero
	
	cmp r8, #0
	bne SkipZero
	
	cmp r9, #0
	bne PlusDenormal
	
	cmp r10, #0
	bne PlusDenormal
	
	mov r0, #0x00
	b return
SkipZero:
	

MinusZero:
	cmp r7, #0
	beq SkipMinusZero
	
	cmp r8, #0
	bne SkipMinusZero
	
	cmp r9, #0
	bne MinusDenormal
	
	cmp r10, #0
	bne MinusDenormal
	
	mov r0, #0x01
	b return
SkipMinusZero:


PlusInf:
	cmp r7, r4
	beq SkipPlusInf

	cmp r8, r5
	bne SkipPlusInf
	
	cmp r9, #0
	bne SignalingNaN
	
	cmp r10, #0
	bne SignalingNaN
	
	mov r0, #0xF0
	b return	
SkipPlusInf:


MinusInf:
	// r4 - sign is plus, r7 number sign
	// r5 exp is 111, r8 number exp
	// r6 mant part 1 is 111, number mant part 1
	
	cmp r7, r4
	bne SkipMinusInf
	
	cmp r8, r5
	bne SkipMinusInf
	
	cmp r9, #0
	bne QuietNaN
	
	cmp r10, #0
	bne QuietNaN
	
	mov r0, #0xF1
	b return
SkipMinusInf:


// Рассмотрели все случаи кроме обычных чисел
// Поэтому достаточно рассмотреть только знак числа
cmp r7, r4
beq MinusRegular
// else

PlusRegular:
	mov r0, #0x10
	b return
SkipPlusRegular:


MinusRegular:
// TODO
	mov r0, #0x11
	b return
PlusDenormal:
	mov r0, #0x20
	b return
MinusDenormal:
	mov r0, #0x21
	b return
SignalingNaN:
	mov r0, #0x30
	b return
QuietNaN:
	mov r0, #0x31
	b return


return:
	pop {r4, r5, r6, r7, r8, r9, r10, r11}
	bx lr
	
