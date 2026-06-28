/* Menu-driven string operations
   Supports: length, copy, concatenate, compare, reverse,
   case conversion, vowel/consonant/digit/space counts, substring search,
   palindrome check, and exit.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void str_length(char s[]) {
    printf("Length: %zu\n", strlen(s));
}

void str_copy(char src[], char dst[]) {
    strcpy(dst, src);
    printf("Copied string: %s\n", dst);
}

void str_concat(char s1[], char s2[]) {
    if (strlen(s1) + strlen(s2) >= MAX) {
        printf("Result would exceed buffer size.\n");
        return;
    }
    strcat(s1, s2);
    printf("Concatenated: %s\n", s1);
}

void str_compare(char s1[], char s2[]) {
    int r = strcmp(s1, s2);
    if (r == 0) printf("Strings are equal.\n");
    else if (r < 0) printf("First string is less than second.\n");
    else printf("First string is greater than second.\n");
}

void str_reverse(char s[]) {
    int i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        char t = s[i]; s[i] = s[j]; s[j] = t;
    }
    printf("Reversed: %s\n", s);
}

void str_case_convert(char s[], int to_upper) {
    for (int i = 0; s[i]; ++i) s[i] = to_upper ? toupper((unsigned char)s[i]) : tolower((unsigned char)s[i]);
    printf("Result: %s\n", s);
}

void str_counts(char s[]) {
    int vowels=0, consonants=0, digits=0, spaces=0, others=0;
    for (int i=0; s[i]; ++i) {
        char c = s[i];
        if (isalpha((unsigned char)c)) {
            char lc = tolower((unsigned char)c);
            if (lc=='a'||lc=='e'||lc=='i'||lc=='o'||lc=='u') vowels++;
            else consonants++;
        } else if (isdigit((unsigned char)c)) digits++;
        else if (isspace((unsigned char)c)) spaces++;
        else others++;
    }
    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nSpaces: %d\nOthers: %d\n",
           vowels, consonants, digits, spaces, others);
}

void str_substring_search(char s[], char sub[]) {
    char *p = strstr(s, sub);
    if (p) printf("Substring found at position %ld (1-based).\n", p - s + 1);
    else printf("Substring not found.\n");
}

void str_is_palindrome(char s[]) {
    int i=0, j=strlen(s)-1;
    while (i<j) {
        while (i<j && !isalnum((unsigned char)s[i])) i++;
        while (i<j && !isalnum((unsigned char)s[j])) j--;
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) { printf("Not a palindrome.\n"); return; }
        i++; j--;
    }
    printf("Palindrome.\n");
}

int main() {
    char s1[MAX] = "", s2[MAX] = "", temp[MAX];
    int choice;

    while (1) {
        printf("\n--- String Operations Menu ---\n");
        printf("1. Enter/Replace first string\n");
        printf("2. Enter/Replace second string\n");
        printf("3. Length of first string\n");
        printf("4. Copy first to second\n");
        printf("5. Concatenate second to first\n");
        printf("6. Compare strings\n");
        printf("7. Reverse first string\n");
        printf("8. Convert case (upper)\n");
        printf("9. Convert case (lower)\n");
        printf("10. Count vowels/consonants/digits/spaces\n");
        printf("11. Find substring in first string\n");
        printf("12. Check palindrome (first string)\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) { getchar(); printf("Invalid input\n"); continue; }
        getchar();

        switch (choice) {
            case 1:
                printf("Enter first string: ");
                fgets(s1, MAX, stdin);
                s1[strcspn(s1, "\n")] = '\0';
                break;
            case 2:
                printf("Enter second string: ");
                fgets(s2, MAX, stdin);
                s2[strcspn(s2, "\n")] = '\0';
                break;
            case 3:
                str_length(s1);
                break;
            case 4:
                str_copy(s1, s2);
                break;
            case 5:
                str_concat(s1, s2);
                break;
            case 6:
                str_compare(s1, s2);
                break;
            case 7:
                str_reverse(s1);
                break;
            case 8:
                str_case_convert(s1, 1);
                break;
            case 9:
                str_case_convert(s1, 0);
                break;
            case 10:
                str_counts(s1);
                break;
            case 11:
                printf("Enter substring to search: ");
                fgets(temp, MAX, stdin);
                temp[strcspn(temp, "\n")] = '\0';
                str_substring_search(s1, temp);
                break;
            case 12:
                str_is_palindrome(s1);
                break;
            case 0:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
