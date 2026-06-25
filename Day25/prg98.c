#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 

void findCommonCharacters(const char *str1, const char *str2) {
    int freq1[MAX_CHAR] = {0};
    int freq2[MAX_CHAR] = {0};
    int found = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]]++;
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]]++;
    }

    printf("Common characters: ");

    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            int min_count = (freq1[i] < freq2[i]) ? freq1[i] : freq2[i];
            
            for (int j = 0; j < min_count; j++) {
                if (i == ' ') {
                    printf("[Space] ");
                } else {
                    printf("%c ", i);
                }
                found = 1;
            }
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char string1[100], string2[100];

    printf("Enter first string: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0'; 

    printf("Enter second string: ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0'; 

    findCommonCharacters(string1, string2);

    return 0;
}
