#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int rlsmd;

	printf("원하는 기능을 입력하시오\n");
	printf("1. 더하기 2. 빼기 3. 곱하기 4. 나누기\n");
	printf("기능 : ");
	scanf_s("%d", &rlsmd);

	if (rlsmd < 1 || rlsmd > 5) {
		printf("잘못 입력하셨습니다.\n");
		exit(0);
	}

	double a, b;
	printf("첫 번째 숫자를 입력하세요 : ");
	scanf_s("%lf", &a);
	printf("두 번째 숫자를 입력하세요 : ");
	scanf_s("%lf", &b);

	if (rlsmd == 1) { printf("%f + %f = %f", a, b, a + b); }
	else if (rlsmd == 2) { printf("%f - %f = %f", a, b, a - b); }
	else if (rlsmd == 3) { printf("%f * %f = %f", a, b, a * b); }
	else if (rlsmd == 4) { printf("%f / %f = %f", a, b, a / b); }

	return 0;
}