#include <stdio.h>

int main() {
    int arr[] = {2, 7, 14, 21, 28, 35};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int even_count = 0;
    int odd_count = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("Even elements: %d\n", even_count);
    printf("Odd elements: %d\n", odd_count);

    return 0;
}
