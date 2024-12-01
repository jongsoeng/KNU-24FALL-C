#include <stdio.h>

int solution(int n) {
    int battery_usage = 0;

    while (n > 0) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n -= 1;
            battery_usage++;
        }
    }

    return battery_usage;
}

int main() {
    printf("Result for N = 5: %d\n", solution(5));
    printf("Result for N = 6: %d\n", solution(6));
    printf("Result for N = 5000: %d\n", solution(5000));

    return 0;
}