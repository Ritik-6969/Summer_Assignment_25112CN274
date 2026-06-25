#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LENGTH 50

int compare_word_lengths(const void *a, const void *b) {
    const char *word_a = *(const char **)a;
    const char *word_b = *(const char **)b;
    
    size_t len_a = strlen(word_a);
    size_t len_b = strlen(word_b);
    
    if (len_a < len_b) return -1;
    if (len_a > len_b) return 1;
    
    return strcmp(word_a, word_b);
}

int main() {
    const char *words[MAX_WORDS] = {
        "Elephant",
        "Cat",
        "Hippopotamus",
        "Dog",
        "Kangaroo",
        "Ox",
        "Giraffe",
        "Lion",
        "Tiger",
        "Mouse"
    };

    printf("Original array of words:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");

    qsort(words, MAX_WORDS, sizeof(char *), compare_word_lengths);

    printf("Words sorted by length (and alphabetically if identical length):\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}
