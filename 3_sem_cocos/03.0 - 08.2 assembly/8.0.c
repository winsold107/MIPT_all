#include <stdio.h>

static int* ptr1 = "asdf";
static char* ptr2 = "q";

static const char* str = "Hello\n";

int main() {
	printf("%s,%d,%c\n",str, *ptr1, *ptr2); 
	return 0;
}
	
