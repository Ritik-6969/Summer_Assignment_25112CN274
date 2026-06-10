#include <stdio.h>

int main() {
    int rows = 5;

    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        for (int j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }

        for (int j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }

        printf("\n");
    }

    return 0;
}
