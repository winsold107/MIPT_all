#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern int N;
extern int *A;
extern int *B;
extern int *R;

extern void summ();
extern void everyday795(int X, int Y);

int main() {
	
	A = (int*)malloc(N*sizeof(int));
	B = (int*)malloc(N*sizeof(int));
	R = (int*)malloc(N*sizeof(int));
	
	for (int i = 0; i < 10; ++i) {
		A[i] = i;
		B[i] = i;
	}
	
	summ();
	
	everyday795(10, 10);
	
	for (int i = 0; i < 10; ++i) {
		printf("%d ", R[i]);
	}
	
	return 0;
}

