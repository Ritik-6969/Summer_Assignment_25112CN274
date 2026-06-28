#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void displayArray(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtEnd(int arr[], int *n, int value) {
    if (*n >= MAX) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    arr[(*n)++] = value;
    printf("Element inserted successfully.\n");
}

void insertAtPosition(int arr[], int *n, int value, int pos) {
    int i;
    if (*n >= MAX) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position.\n");
        return;
    }

    for (i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    (*n)++;
    printf("Element inserted successfully.\n");
}

void deleteAtPosition(int arr[], int *n, int pos) {
    int i;
    if (*n == 0) {
        printf("Array is empty.\n");
        return;
    }
    if (pos < 1 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted successfully.\n");
}

int searchElement(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i + 1;
        }
    }
    return -1;
}

void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
}

void sumAndAverage(int arr[], int n) {
    int i, sum = 0;
    float avg;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    avg = (float)sum / n;
    printf("Sum = %d\nAverage = %.2f\n", sum, avg);
}

int main() {
    int arr[MAX], n, choice, value, pos, result;

    printf("=== Menu-Driven Array Operations System ===\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display array\n");
        printf("2. Insert element at end\n");
        printf("3. Insert element at a position\n");
        printf("4. Delete element from a position\n");
        printf("5. Search element\n");
        printf("6. Sort array\n");
        printf("7. Find sum and average\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, n);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(arr, &n, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(arr, &n, value, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(arr, &n, pos);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &value);
                result = searchElement(arr, n, value);
                if (result == -1) {
                    printf("Element not found.\n");
                } else {
                    printf("Element found at position %d.\n", result);
                }
                break;
            case 6:
                sortArray(arr, n);
                break;
            case 7:
                sumAndAverage(arr, n);
                break;
            case 8:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
