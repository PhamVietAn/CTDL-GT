#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i-1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main(void) {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n < 0 || n > 1000) {
        printf("So luong phan tu khong hop le");
        return 0;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);

    printf("\nMang sau sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}