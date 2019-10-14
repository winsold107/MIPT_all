#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

extern double
calc(double A, double B, double C, int D);

extern double my_sin(double x);

double max(double x, double y) {
	return x > y ? x : y;
}

double abs1(double x) {
	return max(x, -x);
}


void printRes(double prev, double acc, double n) {
	//printf("%lf,\t%lf,\t%lf\n", prev, acc, n);
}

const double eps = 0.00000001;

int main() {
	
//	printf("%lf\n", calc(5.1, 4.8, 1., 2));

	for (double x = 28; x < 55; x+=0.01) {
		double x1 = sin(x), x2 = my_sin(x);
		//printf("%lf\t, %lf\t%lf\n", x1, x2, x);
		//assert(abs1(x1-x2) < eps);
	}
	
	//printf("all tests passed\n");
	


/*
	double prev_acc = x, n = 3;
	double cur_acc = x, cur_addent = x;

	while (1) {
				
		//printRes(prev_acc, cur_acc, n);
		
		cur_addent *= (-1)*x*x/n/(n-1);
		
		cur_acc += cur_addent;
		
		if (cur_acc == prev_acc) {
			break;
		}
		
		prev_acc = cur_acc;
		
		n+=2;
		
	}
	
	//printf("%lf\n", prev_acc);
*/
	return 0;
}

