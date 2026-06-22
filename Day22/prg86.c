#include <stdio.h>
#include <ctype.h> 

int count_words(const char *str) {
    int count = 0;
    int in_word = 0; 

    while (*str != '\0') {
        if (isspace((unsigned char)*str)) {
            in_word = 0; 
        } 
        else if (!in_word) {
            in_word = 1;
            count++; 
        }
        str++;
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        int words = count_words(sentence);
        printf("Number of words: %d\n", words);
    }

    return 0;
}
