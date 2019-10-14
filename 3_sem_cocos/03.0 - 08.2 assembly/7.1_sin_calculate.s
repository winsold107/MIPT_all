//вычисляет значение sin(x)

	.intel_syntax noprefix
	.text
	.global my_sin

# extern double my_sin(double x)

my_sin:
	push ebp
	mov ebp, esp
		
	pushad
		
	# cur_addent
	fld qword ptr [ebp+8]
	
	# prev_acc
	fld qword ptr [ebp+8]
	
	# n
	fld1
	fld1
	fadd st(1), st(0)
	faddp
	
	# cur_acc
	fld st(1)
	
label:
		# n, acc, prev
#		push ecx
#			fld st(1)
#			sub esp, qword
#			fstp qword ptr [esp]
#			
#			sub esp, qword
#			fst qword ptr [esp]
#			
#			sub esp, qword
#			fld st(3)
#			fstp qword ptr [esp]
#			
#			call printRes
#			add esp, 24
#		pop ecx
		
		
		# cur_addent *= (-1)*x*x/n/(n-1);
		# push prev
		fld st(3)
		
		# push x
		fld qword ptr [ebp+8]

		
		fmul st(1), st(0)
		fmulp
		
		# push n
		fld st(2)
		
		fdiv st(1), st(0)
		fld1
		fsubp 
		fdivp
		
		# *(-1)
		fldz
		fld1
		fsubp
		fmulp
		
		
		# UPDATE OLD PREV
		fld st(4)
		fdivp st(5), st(0)
		fmul st(4), st(0)
				
		# UPDATE OLD ACC
		fld st(3)
		fdivp st(4), st(0)
		fmul st(3), st(0)
		
		# ACC+=PREV
		faddp

		#CMP
		fld st(2)
		fcomip st, st(1)
		jz break
		
		
		# UPDATE N+=2
		fld1
		fadd st(2), st(0)
		faddp st(2), st(0)
		
jmp label

break:

	sub esp, qword
	fstp qword ptr [esp]
	fstp st
	fstp st
	fstp st
	fld qword ptr [esp]
	add esp, qword
	
	
	popad
	pop ebp

	ret
