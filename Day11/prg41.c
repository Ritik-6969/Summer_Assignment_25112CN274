#include <stdio.h>

float findSum(float num1, float num2) {
    return num1 + num2;
}

int main() {
    float first_number, second_number, total;

    printf("Enter first number: ");
    scanf("%f", &first_number);
    printf("Enter second number: ");
    scanf("%f", &second_number);

    total = findSum(first_number, second_number);

    printf("The sum is: %.2f\n", total);

    return 0;
}