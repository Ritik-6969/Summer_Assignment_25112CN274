
#include <stdio.h>

unsigned long long findFactorialIterative(int n) {
    if (n < 0) return 0; 
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num = 5;
    printf("The factorial of %d is %llu\n", num, findFactorialIterative(num));
    return 0;
}
