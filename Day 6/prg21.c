#include <stdio.h>

int main() {
    int decimal, i = 0;
    int binary[32];

    printf("Enter a decimal number: ");
    if (scanf("%d", &decimal) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (decimal == 0) {
        printf("Binary equivalent: 0\n");
        return 0;
    }
    while (decimal > 0) {
        binary[i] = decimal % 2; 
        decimal = decimal / 2;
        i++;
    }
    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    return 0;
}
