#include <stdio.h>

int isPerfect(int num) {
    if (num <= 1) return 0;

    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}

int main() {
    int number = 496;
    if (isPerfect(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is NOT a perfect number.\n", number);
    }
    return 0;
}
