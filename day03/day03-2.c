#include<stdio.h>

int fact(int p);

int main(void) {
	int p;

	printf("����� ���丮�� �� �Է� : ");
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