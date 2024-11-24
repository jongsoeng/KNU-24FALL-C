#include <stdio.h>
#include <math.h>

double function(double x) {
    return -log10((double)1/x) + (double)sin(x);
}

double integrate(double (*func)(double), double start, double end, int n) {
    int panel = 1 << n;  // 2^n으로 구간을 나눔
    double dx = (end - start) / panel;  // 각 구간의 너비
    double sum = (func(start) + func(end)) / 2.0;

    for (int i = 1; i < panel; i++) {
        sum += func(start + i * dx);  // 중간 값 더하기
    }

    double result = sum * dx;
    
    for (int i = 0; i <= n; i++) {
        int checkpoint = 1 << i;  // 2^i
        if (panel >= checkpoint) {
            double partial_result = 0.0;
            double partial_dx = (end - start) / checkpoint;
            for (int j = 0; j < checkpoint; j++) {
                partial_result += func(start + j * partial_dx);
            }
            printf("구간 %d 적분 결과 : %.6lf\n", checkpoint, partial_result * partial_dx);
        }
    }

    return result;
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

    double result = integrate(function, start, end, n);
    printf("최종 적분 결과: %.6lf\n", result);

    return 0;
}