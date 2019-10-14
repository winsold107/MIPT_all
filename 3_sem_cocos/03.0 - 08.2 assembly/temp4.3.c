#include <stdio.h>
#include <stdint.h>
#define n 4


typedef struct Person {
    uint32_t  id;
    uint8_t   age;
    char      first_name[20];
    char      last_name[20];
} person_t [n];

extern void
sort_by_age(int N, person_t *persons);

int main() {
	person_t perss;
	for (int i = 0; i < n; i++) {
			perss[i].age = i + 10 - i*2;
			perss[i].id = i + 2;
	}
	
	sort_by_age(n, &perss);
	
	for (int i = 0; i < n; i++) {
			printf("%d", perss[i].age);
	}
	
	return 0;
}
