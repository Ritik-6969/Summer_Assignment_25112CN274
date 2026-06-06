#include <stdio.h>

double calculate_power(double base, int exp) {
    double result = 1.0;
    int is_negative = 0;

    if (base == 0 && exp == 0) {
        return 1.0;
    }
    
    if (base == 0 && exp < 0) {
        printf("Error: Division by zero condition.\n");
        return 0.0; 
    }

    if (exp < 0) {
        is_negative = 1;
        exp = -exp;
    }

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    if (is_negative) {
        return 1.0 / result;
    }

    return result;
}

int main() {
    double x;
    int n;

    printf("Enter base (x): ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid base input.\n");
        return 1;
    }

    printf("Enter integer exponent (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid exponent input.\n");
        return 1;
    }

    double answer = calculate_power(x, n);

    printf("%.2lf raised to the power of %d is: %lf\n", x, n, answer);

    return 0;
}
