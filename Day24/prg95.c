#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char line[1000];
    printf("Enter a sentence:\n");
    if (!fgets(line, sizeof line, stdin))
        return 0;

    int maxLen = 0;
    char longest[1000] = "";
    int len = 0;
    char word[1000];

    for (int i = 0; line[i] != '\0'; ++i) {
        if (!isspace((unsigned char)line[i])) {
            word[len++] = line[i];
        } else if (len > 0) {
            word[len] = '\0';
            if (len > maxLen) {
                maxLen = len;
                strcpy(longest, word);
            }
            len = 0;
        }
    }

    if (len > 0) {
        word[len] = '\0';
        if (len > maxLen) {
            maxLen = len;
            strcpy(longest, word);
        }
    }

    if (maxLen > 0) {
        printf("Longest word: %s\nLength: %d\n", longest, maxLen);
    } else {
        printf("No words found.\n");
    }

    return 0;
}
