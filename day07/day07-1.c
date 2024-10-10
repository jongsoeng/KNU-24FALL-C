#include<stdio.h>

int main(void){
    int p;

    printf("피라미드 층 입력 : ");
    scanf("%d", &p);
    printf("%d층 피라미드\n", p);
    
    for (int i = 0; i < p; i++) {
        for (int j = p - 1; j > i; j--) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}