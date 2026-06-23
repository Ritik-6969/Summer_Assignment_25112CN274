#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkAnagram(const char *str1, const char *str2) {
    int count[256] = {0};
    
    if (strlen(str1) != strlen(str2)) {
        return false;
    }
    
    for (int i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter the first string: ");
    scanf("%99s", str1);
    
    printf("Enter the second string: ");
    scanf("%99s", str2);
    
    if (checkAnagram(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }
    
    return 0;
}
