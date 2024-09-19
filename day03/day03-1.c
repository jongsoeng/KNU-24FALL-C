#include<stdio.h>

int prime_number(int k);

int main(void) {
	int a;

	printf("�Ҽ������� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &a);

	if (prime_number(a))
		printf("�Ҽ�����");
	else 
		printf("�Ҽ��� �ƴϿ���");

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