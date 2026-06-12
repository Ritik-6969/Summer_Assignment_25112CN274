#include <stdio.h>
void printFibonacciIterative(int n) {
    int t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            printf("%d ", t1);
            continue;
        }
        if (i == 2) {
            printf("%d ", t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        printf("%d ", nextTerm);
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printFibonacciIterative(terms);
    }

    return 0;
}
