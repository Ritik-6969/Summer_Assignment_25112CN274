#include <stdio.h>

int main() {
    long long num;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%lld", &num);

    if (num == 0) {
        count = 1;
    } else {
        if (num < 0) {
            num = -num;
        }
        
        while (num != 0) {
            num /= 10;
            count++;
        }
    }

    printf("Number of digits: %d\n", count);

    return 0;
}
