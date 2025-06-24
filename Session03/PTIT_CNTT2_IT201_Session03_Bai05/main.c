#include <stdio.h>
#include <stdlib.h>

int MaxNum(int **arr,int row, int col) {
    int max = arr[0][0];
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int MinNum(int **arr,int row, int col) {
    int min = arr[0][0];
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int main(void) {
    int col,row;

    do {
        printf("Nhap so hang: ");
        scanf("%d", &row);
        if (row < 0 || row >1000) {
            printf("So hang khong hop le\n");
        }
    }while (row<0 || row >1000);

    do {
        printf("Nhap so cot: ");
        scanf("%d", &col);
        if (col < 0 || col >1000) {
            printf("So cot khong hop le\n");
        }
    }while (col < 0 || col >1000);

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

    int max = MaxNum(arr, row, col);
    int min = MinNum(arr, row, col);

    printf("Max %d", max);
    printf("Min %d", min);

    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}