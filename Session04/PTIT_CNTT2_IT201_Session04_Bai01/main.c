#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int value) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            end = mid - 1;
        }
        if (arr[mid] < value) {
            start = mid + 1;
        }
    }
    return -1;
}

int main(void) {
    int n;
    int* arr = (int*)malloc(n * sizeof(int));

    do {
        printf("Nhap so phan tu trong mang: ");
        scanf("%d", &n);
        if (n<1) {
            printf("So phan tu khong hop le. Vui long nhap lai\n");
        }
    }while (n < 1);

    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ",i);
        scanf("%d", &arr[i]);
    }

    int value;

    printf("Nhap gia tri muon tim kiem trong mang: ");
    scanf("%d", &value);

    int result = binarySearch(arr, n, value);
    if (result == -1) {
        printf("Khong tim thay phan tu\n");
    } else {
        printf("%d", result);
    }

    return 0;
}