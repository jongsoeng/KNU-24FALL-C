#include<stdio.h>

int prime_number(int k);

int main(void) {
	int a;

	printf("소수인지를 확인할 수를 입력하세요 : ");
	scanf_s("%d", &a);

	if (prime_number(a))
		printf("소수에요");
	else 
		printf("소수가 아니에요");

	return 0;
}

int prime_number(int k) {
	if (k <= 1)
		return 0;

	for (int i = 2; i * i <= k; i++) {
		if (k % i == 0)
			return 0;
	}

	return 1;
}