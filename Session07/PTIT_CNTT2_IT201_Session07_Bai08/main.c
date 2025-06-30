#include <stdio.h>

void swap(int a[], int b[], int col) {
    for (int i = 0; i < col; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int partition(int arr[][1000], int low, int high, int k, int col) {
    int pivot = arr[high][k];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j][k] <= pivot) {
            i++;
            swap(arr[i], arr[j], col);
        }
    }
    swap(arr[i + 1], arr[high], col);
    return i + 1;
}

void quickSort(int arr[][1000], int low, int high, int k, int col) {
    if (low < high) {
        int pi = partition(arr, low, high, k , col);
        quickSort(arr, low, pi - 1, k, col);
        quickSort(arr, pi + 1, high, k, col);
    }
}

int main(void) {
    int row, col;
    int arr[1000][1000];

    printf("rows: ");
    scanf("%d", &row);
    if (row <= 0 || row > 1000) {
        printf("So hang khong hop le\n");
        return 1;
    }

    printf("cols: ");
    scanf("%d", &col);
    if (col <= 0 || col > 1000) {
        printf("So cot khong hop le\n");
        return 1;
    }


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int k;
    printf("Nhap so cot muon sap xep (tu 0 den %d): ", col - 1);
    scanf("%d", &k);
    if (k < 0 || k >= col) {
        printf("So cot khong hop le\n");
        return 1;
    }

    printf("Ma tran truoc khi sap xep:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    quickSort(arr, 0, row - 1, k, col);

    printf("Ma tran sau khi sap xep theo cot %d:\n", k);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
