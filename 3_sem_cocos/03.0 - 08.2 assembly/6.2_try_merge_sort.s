#trying of mergesort

	.global mergeSort
	.intel_syntax noprefix
	.text
	
	
	
# exten void mergesort(ebp + 4 = int from, ebp + 8 = int to, ebp + 12 = const int *in, ebp + 16 = int *out);		
	
	
MergeSort:
     push eax                      # save used register
     mov  eax, [esp+12]             # eax = right
     cmp  eax, [esp+8]            # left = right?
     je   .L1                      # YES - exit
     add  eax, [esp+8]            # NO  - eax = left+right
     shr  eax, 1                   # eax = mid (left+right)/2

     push dword [esp+16]           # 1st recursive call
     push dword [esp+16]	   # sort(arr, left, mid)
     push eax
     call MergeSort 

     push dword [esp+16]	   # 2nd recursive call
     push eax                      # sort(arr, mid+1, right)
     inc  dword [esp]
     push dword [esp+16]
     call MergeSort

     push dword [esp+16]           # merge(arr, left, mid, right)
     push dword [esp+16]
     push eax
     push dword [esp+20]
     call Merge

.Link1: pop  eax
     ret  3*4	
	
	
Merge:                            # [arr & left & (left+right)/2=mid & right] INTO 	[left & right & in* & out*] 
     push ebp
     mov  ebp, esp	    	  # compose stack frame
     pushad		          	  # save used regs

     mov  ebx, [ebp+16]           # ebx = &array
     mov  esi, [ebp+8]           # esi = left
     mov  edi, [ebp+12]			 # edi = right
     add  edi, esi
     shr edi, 1					  # divide by 2
     adc edi, 0					  # round up -----> edi is the middle 
     inc  edi                     # edi = m+1
     mov  ecx, 0                  # ecx = k = 0

.L0: 
	 mov  edx, [ebp+12]			 # edx = right
     add  edx, esi
     shr edx, 1					  # divide by 2
     adc edx, 0					  # round up -----> edx is the middle 
     inc  edx
		
	 cmp  esi, edx		          # while (l<=m && r<=j)
     jg   .L2					  # jump if greater (if while is skipped)
     cmp  edi, [ebp+12]			  
     jg   .L2

     mov  eax, [ebx+esi*4]        # eax = a[l]
     cmp  eax, [ebx+edi*4]        # if (a[l] < a[r]) 						HERE IS THE QUESTION WHY R IF ITS MID?
     jge  .L1					  # jump if greater or equal
     mov  [ebp+20+ecx*4], eax     # out[k] = a[l] (out turned by aux)
     inc  ecx                     # k++
     inc  esi                     # l++
     jmp  .L0

.L1: 
	 mov  eax, [ebx+edi*4]        # else
     mov  [ebp+20+ecx*4], eax     # out[k] = a[r]						
     inc  ecx                     # k++
     inc  edi                     # l++										EDI IS MID NOT LEFT
     jmp  .L0


.L2: 
	 cmp  esi, edx		          # while (l<=m)
     jg   .L3
     mov  eax, [ebx+esi*4]        # out[k] = a[l];
     mov  [ebp+20+ecx*4], eax
     inc  esi                     # l++
     inc  ecx                     # k++
     jmp  .L2

.L3: 
	 cmp  edi, [ebp+12]            # while (r<=j)
     jg   .L4
     mov  eax, [ebx+edi*4]        # out[k] = a[r];
     mov  [ebp+20+ecx*4], eax
     inc  edi                     # r++										AGAIN R NOT MID WHY?
     inc  ecx                     # k++
     jmp  .L3

.L4: 
	 mov  esi, [ebp+8]           # esi = i
     shl  esi, 2                  # esi = i*4
     add  ebx, esi
     mov  ecx, 0                  # ecx = k = 0     
     mov  esi, [ebp+12]
     sub  esi, [ebp+8]
     inc  esi                     # esi = j-i+1 = out.length

.L5: 
	 cmp  ecx, esi                # for (k=0; k<out.length; k++)
     jge  .L6
     mov  eax, [ebp+20+ecx*4]        # a[i+k] = aux[k];
     mov  [ebx+ecx*4], eax
     inc  ecx                     # k++
     jmp  .L5

.L6: 
	 popad                        # restore regs
     pop ebp
     ret 4*4
