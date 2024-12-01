#include <stdio.h>
#include <stdlib.h>

int solution(int* topping, int toppingSize) {
    int* left_count = (int*)calloc(10001, sizeof(int));
    int* right_count = (int*)calloc(10001, sizeof(int));
    int left_unique = 0, right_unique = 0, result = 0;

    for (int i = 0; i < toppingSize; i++) {
        if (right_count[topping[i]] == 0) {
            right_unique++;
        }
        right_count[topping[i]]++;
    }

    for (int i = 0; i < toppingSize - 1; i++) {
        if (left_count[topping[i]] == 0) {
            left_unique++;
        }
        left_count[topping[i]]++;

        right_count[topping[i]]--;
        if (right_count[topping[i]] == 0) {
            right_unique--;
        }

        if (left_unique == right_unique) {
            result++;
        }
    }

    free(left_count);
    free(right_count);
    return result;
}

int main() {
    int topping[] = {1, 2, 1, 3, 1, 4, 1, 2};
    int toppingSize = sizeof(topping) / sizeof(topping[0]);
    printf("공평하게 자르는 방법의 수: %d\n", solution(topping, toppingSize));
    return 0;
}