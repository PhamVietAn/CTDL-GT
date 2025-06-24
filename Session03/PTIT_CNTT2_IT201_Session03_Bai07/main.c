#include <stdio.h>
#include <stdlib.h>

int sumRow(int **arr, int k, int cols) {
    int sum = 0;
    for (int i = 0; i < cols; i++) {
        sum += arr[k][i];
    }
    return sum;
}

int main(void) {
    int col,row;

    do {
        printf("Nhap so hang: ");
        scanf("%d", &row);
        if (row < 0 || row >1000) {
            printf("So hang khong hop le\n");
        }
    }while (row<=0 || row >=1000);

    do {
        printf("Nhap so cot: ");
        scanf("%d", &col);
        if (col < 0 || col >1000) {
            printf("So cot khong hop le\n");
        }
    }while (col <= 0 || col >=1000);

    int **arr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        arr[i] = (int *)malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int k;
    do {
        printf("Nhao chi so hang k: ");
        scanf("%d", &k);
        if (k < 0 || k >= row) {
            printf("So hang khong hop le\n");
        }
    }while (k < 0 || k >= row);

    int total = sumRow(arr, k, col);
    printf("Tong cac phan tu cua hang %d la: %d", k, total);

    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}