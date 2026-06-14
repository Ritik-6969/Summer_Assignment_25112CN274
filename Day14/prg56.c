#include <stdio.h>
#include <stdbool.h>

void findDuplicates(int arr[], int size) {
    bool hasDuplicate = false;
    
    printf("Duplicate elements in the array: ");
    
    for (int i = 0; i < size; i++) {
        bool alreadyPrinted = false;
        
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                alreadyPrinted = true;
                break;
            }
        }
        
        if (!alreadyPrinted) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    printf("%d ", arr[i]);
                    hasDuplicate = true;
                    break; 
                }
            }
        }
    }
    
    if (!hasDuplicate) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 7, 4, 8, 2, 4, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    findDuplicates(arr, size);
    
    return 0;
}
