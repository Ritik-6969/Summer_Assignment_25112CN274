#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_rotation(const char *s1, const char *s2) {
    if (!s1 || !s2) return 0;
    size_t n1 = strlen(s1);
    size_t n2 = strlen(s2);
    if (n1 != n2) return 0;
    if (n1 == 0) return 1; 

    size_t buf_len = n1 * 2 + 1;
    char *buf = malloc(buf_len);
    if (!buf) return 0;
    strcpy(buf, s1);
    strcat(buf, s1);

    char *res = strstr(buf, s2);
    free(buf);
    return res != NULL;
}

int main(void) {
    char s1[1024];
    char s2[1024];

    printf("Enter first string: ");
    if (!fgets(s1, sizeof(s1), stdin)) return 0;
    printf("Enter second string: ");
    if (!fgets(s2, sizeof(s2), stdin)) return 0;

    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    if (is_rotation(s1, s2))
        printf("Yes: '%s' is a rotation of '%s'\n", s2, s1);
    else
        printf("No: '%s' is NOT a rotation of '%s'\n", s2, s1);

    return 0;
}
