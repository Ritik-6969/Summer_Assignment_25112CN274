#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];

    printf("Enter a lowercase string: ");
    fgets(str, sizeof(str), stdin); 

    
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }

    printf("Uppercase string: %s", str);

    return 0;
}
