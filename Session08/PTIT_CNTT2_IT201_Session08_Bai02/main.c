#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int *arr, int left, int right, int key) {
    if (left > right) {
        return -1;
    }
    int mid = (right + left) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        return binarySearch(arr, left, mid - 1, key);
    } else {
        return binarySearch(arr, mid + 1, right, key);
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

    int search;
    printf("Nhap phan tu muon tim kiem: ");
    scanf("%d", &search);

    sort(arr, n);

    int result = binarySearch(arr, 0, n - 1, search);

    if (result == -1) {
        printf("Khong tim thay");
    } else {
        printf("Vi tri thu %d", result + 1);
    }
    free(arr);

    return 0;
}