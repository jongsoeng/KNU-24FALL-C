#include<stdio.h>

int fact(int p);

int main(void) {
	int p;

	printf("계산할 팩토리얼 값 입력 : ");
	scanf_s("%d", &p);
	int result = fact(p);
	printf("%d  = %d", p, result);

	return 0;
}

int fact(int p) {
	int res;
	if (p == 0 || p == 1) {
		res = 1;
		return res;
	}

	res = p * fact(p - 1);
	return res;
}