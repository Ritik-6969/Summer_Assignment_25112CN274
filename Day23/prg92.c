#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

char getMaxOccurringChar(char* str) {
    int count[MAX_CHARS] = {0};

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] != '\n') {
            count[(unsigned char)str[i]]++;
        }
    }

    int max = -1; 
    char result;   

    for (int i = 0; i < len; i++) {
        if (str[i] != '\n' && max < count[(unsigned char)str[i]]) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }

    return result;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    char maxChar = getMaxOccurringChar(str);

    printf("The maximum occurring character is: '%c'\n", maxChar);

    return 0;
}
