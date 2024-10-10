#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(void) {
    double x = 0;
    double y = 0;
    int percent = 0;
    long long count = 0, circle = 0;

    srand(time(NULL));

    while (count < 10000000) {
        x = (double)rand() / (double)RAND_MAX;
        y = (double)rand() / (double)RAND_MAX;
        if (x*x + y*y <= 1) {
            circle++;
        }
        count ++;
        if (count % 100000 == 0) {
            percent = count / 100000;
            double PI = (double)circle / count * 4;
            printf("%d%% 진행.. 원주율 : %lf ", percent, PI);
            int bar = percent / 5;
            for (int i = 0; i < 20; i++) {
                if (i < bar)
                    printf("■");
                else
                    printf("□");
            }
            printf("\n");
        }
    }
    return 0;
}