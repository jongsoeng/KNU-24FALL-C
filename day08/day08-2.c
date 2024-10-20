/*10x10 크기의2차원배열을임의의수(1~20 범위)로초기화
rand()함수이용
배열의값만큼이동하고, 현재위치(x,y)와배열의값을출력
시작위치는(0,0)
이동은포인터연산을이용:*(array + n)
더이상이동할수없을때, 최종위치출력후프로그램종료*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define SIZE 10

void fileRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main(void) {
    int array[SIZE][SIZE];

    fileRandom(array); // 배열 랜덤 초기화
    printArray(array); // 배열 출력
    movePointer(array); // 포인터를 이용한 이동

    return 0;
}

void fileRandom(int array[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            array[i][j] = rand() % 20 + 1;
    }
}

void printArray(int array[SIZE][SIZE]) {
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++)
                printf("%2d ", array[i][j]);
            printf("\n");
        }
}

void movePointer(void* array) {
    int a = 0, b = 0;
    int *ptr = (int*)array;

    printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", a,b, *ptr);

    while (1) {
        b += *ptr;
        if(a == 8 && b >= 20 || a == 9 && b >= 10){
            b = b - *ptr;
            break;
        }
        ptr = ptr + *ptr;
        if (b > 9) { // b가 9를 넘어가면 a를 증가시키고 b를 조정
            a += b / SIZE; // a를 넘어진 만큼 증가
            b = b % SIZE;  // b는 SIZE를 넘지 않도록 조정
        }

        printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", a,b, *ptr);
    }
    
    printf("더이상 이동 할 수 없습니다.\n");
    printf("종료 위치 : (%d, %d), 배열의 값 : %d\n", a, b, *ptr);
}