#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256
char findFirstRepeating(char *str) {
    int count[MAX_CHARS] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        if (count[ch] > 0) {
            return str[i];
        }

        count[ch]++;
    }

    return '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}
