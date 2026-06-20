#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and cols for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error: Columns of 1st must equal rows of 2nd.\n");
        return 1;
    }

    int first[r1][c1], second[r2][c2], result[r1][c2];
    printf("\nEnter 1st matrix elements:\n");
    for(int i=0; i<r1; i++) for(int j=0; j<c1; j++) scanf("%d", &first[i][j]);

    printf("Enter 2nd matrix elements:\n");
    for(int i=0; i<r2; i++) for(int j=0; j<c2; j++) scanf("%d", &second[i][j]);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    printf("\nResultant Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) printf("%d ", result[i][j]);
        printf("\n");
    }
    return 0;
}
