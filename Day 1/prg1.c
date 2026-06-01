#include <stdio.h>

int main() {
    int n;
    int sum = 0;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("The sum of the first %d natural numbers is: %d\n", n, sum);

    return 0;
}
