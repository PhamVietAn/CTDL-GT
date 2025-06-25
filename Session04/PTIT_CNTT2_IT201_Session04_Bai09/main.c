#include <stdio.h>

int binarySearch(int arr[], int left, int right, int number) {
    if (left > right) {
        return 0;
    }
    int mid = (left + right) / 2;
    if (number == arr[mid]) {
        return mid;
    }else if (number < arr[mid]) {
        return binarySearch(arr, left, mid - 1, number);
    }else {
        return binarySearch(arr, mid + 1, right, number);
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int number;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &number);
    if (binarySearch(arr, 0, n - 1, number) == 1) {
        printf("Phan tu co trong mang");
    } else {
        printf("Phan tu khong co trong mang");
    }
    return 0;
}