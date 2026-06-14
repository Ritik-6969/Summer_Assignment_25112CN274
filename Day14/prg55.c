#include <stdio.h>
#include <limits.h>

int main() {
    int arr[100], size, i;
    int largest, second_largest;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size < 2) {
        printf("Error: Array must contain at least 2 elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    largest = INT_MIN;
    second_largest = INT_MIN;

    for (i = 0; i < size; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } 
        else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    if (second_largest == INT_MIN) {
        printf("There is no second largest distinct element (all elements might be equal).\n");
    } else {
        printf("The largest element is: %d\n", largest);
        printf("The second largest element is: %d\n", second_largest);
    }

    return 0;
}
