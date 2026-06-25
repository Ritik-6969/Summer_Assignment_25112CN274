#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n;
    char names[MAX_NAMES][MAX_LENGTH];
    
    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar(); 

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        fgets(names[i], MAX_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }
    
    qsort(names, n, sizeof(names[0]), compare);
    
    printf("\nNames sorted alphabetically:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
    
    return 0;
}
