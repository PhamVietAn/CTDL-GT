#include <stdio.h>

void printMatrix(int a[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/*
 * thời gian: O(n * m)
 * không gian: O(1)
 */

void printDiagonal(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}
/*
 * thời gian: O(n)
 * không gian: O(1)
 */