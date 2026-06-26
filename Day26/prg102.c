#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("Congratulations! You are eligible to vote.\n");
    } else if (age > 0) {
        printf("Sorry, you are not eligible to vote yet.\n");
        printf("You must wait %d more year(s) to vote.\n", 18 - age);
    } else {
        printf("Invalid age entered. Please enter a positive number.\n");
    }

    return 0;
}
