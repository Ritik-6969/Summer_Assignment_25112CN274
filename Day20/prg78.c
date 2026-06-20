#include <stdio.h>

int main() {
    int rows, cols;
    int i, j;
    int isSymmetric = 1;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("\nThe matrix is NOT symmetric (It must be a square matrix).\n");
        return 0;
    }

    int matrix[rows][cols];

    printf("\nEnter elements of the matrix (%dx%d):\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = i + 1; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Breakdown found
                break;
            }
        }
        if (!isSymmetric) {
            break; 
        }
    }

    printf("\nEntered Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    if (isSymmetric) {
        printf("\nThe given matrix is a Symmetric Matrix.\n");
    } else {
        printf("\nThe given matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}
