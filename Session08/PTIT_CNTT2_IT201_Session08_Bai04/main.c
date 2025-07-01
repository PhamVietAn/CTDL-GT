#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    selectionSort(arr, n);

    printf("\nMang sau sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}