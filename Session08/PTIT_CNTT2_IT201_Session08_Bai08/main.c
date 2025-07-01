#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int linerSearch(int arr[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Tim thay %d o vi tri %d\n", key, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu\n");
        return -1;
    }
    return 1;
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

    printf("Mang truoc sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    InsertionSort(arr, n);

    printf("\nMang sau sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int key;
    printf("\nNhap phan tu muon tim kiem: ");
    scanf("%d", &key);

    int index1 = binarySearch(arr, 0, n - 1, key);
    printf("Binary Search: ");
    if (index1 == -1) {
        printf("khong tim thay phan tu");
    } else {
        printf("Tim thay %d tai vi tri %d\n", key, index1);
    }

    printf("Liner Search: ");
    linerSearch(arr, n, key);


    free(arr);

    return 0;
}