#include <stdio.h>

int countSetBits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); 
        count++;        
    }
    return count;
}

int main() {
    unsigned int num;

    printf("Enter an unsigned integer: ");
    if (scanf("%u", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int result = countSetBits(num);
    printf("The number of set bits (1s) in %u is: %d\n", num, result);

    return 0;
}
