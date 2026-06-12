#include <stdio.h>
#include <math.h>

int isArmstrong(int num);

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}

int isArmstrong(int num) {
    int originalNum = num;
    int temp = num;
    int digits = 0;
    int sum = 0;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp != 0) {
        int remainder = temp % 10;
        
        sum += (int)round(pow(remainder, digits)); 
        
        temp /= 10;
    }

    if (sum == originalNum) {
        return 1; 
    } else {
        return 0; 
    }
}
