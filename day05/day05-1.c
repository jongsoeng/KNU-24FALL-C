#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	int N;
	int* number;
	char** name;		//char* = name;
	int* score;

	printf("N 입력 : ");
	scanf_s("%d", &N);

	number = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));		// name = (char*)malloc(N * 100 * sizeof(char));
	score = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < N; i++) {
		printf("%d번째 학생 학번 입력 : ", i+1);
		scanf_s("%d", &number[i]);

		printf("%d번째 학생 이름 입력 : ", i+1);
		scanf_s("%s", name[i], 100); //scanf_s("%s", name+(100*i), 100);

		printf("%d번째 학생 점수 입력 : ", i+1);
		scanf_s("%d", &score[i]);
	}
	printf("\n");

	for (int i = 0; i < N; i++) {
		printf("%s %d %d\n", name[i], number[i], score[i]);		//print("%d %s %d", number[i], name+(100*i), score[i]);
	}
	printf("\n");

	int max = score[0], min = score[0], sum = 0, avr;

	for (int i = 0; i < N; i++) {
		if (score[i] > max) max = score[i];
		if (score[i] > min) min = score[i];
		sum += score[i];
	}

	avr = sum / N;

	printf("최대값 : %d\n최소값 : %d\n평균값 : %d", max, min, avr);

	free(number);
	free(name);
	free(score);

	number = NULL;
	name = NULL;
	score = NULL;

	return 0;
}