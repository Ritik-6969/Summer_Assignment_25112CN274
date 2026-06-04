#include <stdio.h>

int main() {
    unsigned long long int num, originalNum, remainder, n = 0;
    unsigned long long int result = 0;

    printf("Enter an integer: ");
    scanf("%llu", &num);

    originalNum = num;

    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;

        unsigned long long int power = 1;
        for (unsigned long long int i = 0; i < n; i++) {
            power *= remainder;
        }

        result += power;
        originalNum /= 10;
    }

    if (result == num)
        printf("%llu is an Armstrong number.\n", num);
    else
        printf("%llu is not an Armstrong number.\n", num);

    return 0;
}