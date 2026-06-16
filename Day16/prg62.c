#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    int visited[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }

    int max_element = arr[0];
    int max_count = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }

        if (count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }

    printf("\nElement with maximum frequency: %d\n", max_element);
    printf("It appears %d times.\n", max_count);

    return 0;
}
