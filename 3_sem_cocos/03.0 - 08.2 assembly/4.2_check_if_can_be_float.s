//Функция должна вернуть 1, если число может быть представлено типом float, или 0, - если не 		//может.	

.text
	.global check_int
check_int:
	cmp r0, #0
	beq return
	mov r1, #1
loop:
	and r2, r0, r1
	cmp r2, #1
	beq check
	lsr r0, #1
	b loop
check:
	mov r3, #0xff000000
	mvn r3, r3
	cmp r0, r3
	bls return
	mov r0, #0
	bx lr
return:
	mov r0, #1
	bx lr
