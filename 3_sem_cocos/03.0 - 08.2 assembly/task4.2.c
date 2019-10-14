#include <stdint.h>
#include <stdio.h>

extern int check_int(uint32_t u32); /* retval: 0 - false, 1 - true */

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {
	uint32_t u32;
	scanf ("%d", &u32); 

	int i = u32;
        //uint32_t ui = 999999999;
        //float f = 23.45f;
        printBits(sizeof(i), &i);
        printf("\n");
        //printBits(sizeof(ui), &ui);
        //printf("\n");
        //printBits(sizeof(f), &f);
		//printf("\n");
	
	printf("%d", check_int(u32));
	return 0;
}

