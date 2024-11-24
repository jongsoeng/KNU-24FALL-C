#include <stdio.h>
#include <math.h>

double function(double x) {
    return x * x + 1;
}

double integrate(double (*func)(double),double start, double end, int n) {
    double dx = (end - start) / n;
    double sum = (func(start) + func(end)) / 2.0;
    int check = 1;
    double result = 0;
    double panel = pow(2, n);

    for (int i = 1; i < panel; i++) {
        result += sum * dx;
        if (i == check) {
            printf("구간 %d 적분 결과 : %.6lf\n", i, result);
            check *= 2;
        }
    }

    return sum * dx;
}

int main(void) {
    double start, end;
    int n;

    printf("적분할 시작 값을 입력하세요 : ");
    scanf("%lf", &start);
    printf("적분할 끝 값을 입력하세요 : ");
    scanf("%lf", &end);
    printf("시행할 최대 구간을 입력하세요 (2^n) : ");
    scanf("%d", &n);

    integrate(function, start, end, n);

    return 0;
}