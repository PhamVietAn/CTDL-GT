#include <stdio.h>
#include <stdlib.h>

int findIndex(int* arr, int size, int value) {
    int index = 0;
    int check = -1;
    for (int i = 1; i < size; i++) {
        if (arr[i] == value) {
            index = i;
            check = 1;
        }
    }
    if (check == 1) {
        return index;
    } else {
        return -1;
    }
}

int main(void) {
    int n;

    do {
        printf("Nhap so phan tu trong mang: ");
        scanf("%d", &n);
        if (n<1) {
            printf("So phan tu khong hop le. Vui long nhap lai\n");
        }
    }while (n < 1);
    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ",i);
        scanf("%d", &arr[i]);
    }

    int value;
    do {
        printf("Nhap phan tu muon tim kiem: ");
        scanf("%d", &value);
        if (value < 0) {
            printf("Khong hop le.");
        }
    }while (value < 1);

    int min = findIndex(arr, n, value);
    if (min == -1) {
        printf("Khong tim thay");
        return 0;
    }
    printf("%d\n", min);


    return 0;
}