#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES

int main(void) {
    int a,b,c;

    printf("실수 a, b, c 입력\n");
    scanf("%d %d %d", &a, &b, &c);

    double equ = b * b - 4.0 * a * c;
    double denom = 2.0 * a;

    if (equ == 0) {
        printf("방정식 %dx^2 + (%d)x + (%d)는 중근을 가집니다.\n", a, b, c);
        double result = -b / denom;
        printf("따라서 %.2lf의 근을 가집니다.\n", result);
    }
    else if (equ < 0) {
        printf("방정식 %dx^2 + (%d)x + (%d)는 허근을 가집니다.\n", a, b, c);
    }
    else {
        printf("방정식 %dx^2 + (%d)x + (%d)는 실근을 가집니다.\n", a, b, c);
        double result1 = (-b - sqrt(equ)) / denom;
        double result2 = (-b + sqrt(equ)) / denom;
        printf("따라서 %.2lf와 %.2lf의 근을 가집니다.\n", result1, result2);
    }

    return 0;
}