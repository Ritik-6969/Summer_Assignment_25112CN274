#include <stdio.h>

int findMax(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int a = 45;
    int b = 82;
    
    int result = findMax(a, b);
    
    printf("The maximum number between %d and %d is: %d\n", a, b, result);
    return 0;
}
