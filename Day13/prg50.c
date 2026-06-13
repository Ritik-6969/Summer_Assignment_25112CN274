#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Calculate array length
    int sum = 0;
    float average;

    for(int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    average = (float)sum / size;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
