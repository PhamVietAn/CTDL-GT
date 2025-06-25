#include <stdio.h>
#include <stdlib.h>

int findMin(int* arr, int size) {
    int min = arr[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }
    return index;
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

    int min = findMin(arr, n);
    printf("%d\n", min);


    return 0;
}