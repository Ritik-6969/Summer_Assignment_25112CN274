#include <stdio.h>
#include <string.h>

void removeSpaces(char *str) {
    int readIndex = 0;
    int writeIndex = 0;

    while (str[readIndex] != '\0') {
        if (str[readIndex] != ' ') {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }
    
    str[writeIndex] = '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';

        printf("Original string: '%s'\n", str);
        removeSpaces(str);

        printf("String after removing spaces: '%s'\n", str);
    }

    return 0;
}
