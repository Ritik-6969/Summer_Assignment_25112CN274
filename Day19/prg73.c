#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], sum[r][c];
    printf("\nEnter elements of matrix A:\n");
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j) scanf("%d", &a[i][j]);
    printf("Enter elements of matrix B:\n");
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j) scanf("%d", &b[i][j]);
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j) sum[i][j] = a[i][j] + b[i][j];
    printf("\nSum of matrices:\n");
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j) printf("%d ", sum[i][j]);
    return 0;
}
