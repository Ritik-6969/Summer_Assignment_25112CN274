#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left, right;
    int isPalindrome = 1; 

    printf("Enter a string: ");
    scanf("%99s", str); 

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0; 
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
