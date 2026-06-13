#include <stdio.h>

int main() {
    int arr[] = {34, 12, 89, 5, 45, 92, 21};
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    int smallest = arr[0];
    int largest = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    printf("Smallest element: %d\n", smallest);
    printf("Largest element: %d\n", largest);
    
    return 0;
}
