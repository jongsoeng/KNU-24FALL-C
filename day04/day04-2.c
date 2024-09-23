#include<stdio.h>

void swap(int* a, int* b);

int main(void) {
	int a = 10, b = 20;
	printf("a = %d\nb = %d\n\n", a, b);

	swap(&a, &b);
	
	printf("a = %d\nb = %d\n", a, b);

	return 0;
}

void swap(int* a, int* b) {
	int k = *a;
	*a = *b;
	*b = k;
}