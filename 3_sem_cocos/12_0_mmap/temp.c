#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	FILE* f = fopen("output.txt", "w");
	srand(time(NULL));
	for (int i = 0; i < 10000000; ++i) {
		fprintf(f, "%d\n", rand());
	};
	return 0;
}
