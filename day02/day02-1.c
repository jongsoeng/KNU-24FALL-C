#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int rlsmd;

	printf("���ϴ� ����� �Է��Ͻÿ�\n");
	printf("1. ���ϱ� 2. ���� 3. ���ϱ� 4. ������\n");
	printf("��� : ");
	scanf_s("%d", &rlsmd);

	if (rlsmd < 1 || rlsmd > 5) {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		exit(0);
	}

	double a, b;
	printf("ù ��° ���ڸ� �Է��ϼ��� : ");
	scanf_s("%lf", &a);
	printf("�� ��° ���ڸ� �Է��ϼ��� : ");
	scanf_s("%lf", &b);

	if (rlsmd == 1) { printf("%f + %f = %f", a, b, a + b); }
	else if (rlsmd == 2) { printf("%f - %f = %f", a, b, a - b); }
	else if (rlsmd == 3) { printf("%f * %f = %f", a, b, a * b); }
	else if (rlsmd == 4) { printf("%f / %f = %f", a, b, a / b); }

	return 0;
}