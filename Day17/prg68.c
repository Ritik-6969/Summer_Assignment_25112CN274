#include <stdio.h>
int main()
{
    int a[6] = { 1, 2, 3, 4, 5, 6 };
    int b[6] = { 5, 6, 7, 8, 9, 10 };
    int c[10], i, j, k = 0, x, count;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {

            if (a[i] == b[j]) {
                count = 0;
                for (x = 0; x < k; x++) {
                    if (a[i] == c[x])
                        count++;
                }

                if (count == 0) {
                    c[k] = a[i];
                    k++;
                }
            }
        }
    }
    printf("Common array elements is \n");
    for (i = 0; i < k; i++)
      
        printf("%d ", c[i]);
    return 0;
}