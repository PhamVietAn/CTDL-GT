#include <stdio.h>

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void delete(int arr[], int n, int pos) {
    for (int i = pos; i < n; i++) {
        arr[i] = arr[i+1];
    }
}

int main () {
    int arr[100];
    int n, position;

    do{
        printf("nhap so luong phan tu co trong mang (0<n<100): ");
        scanf("%d", &n);
        if (n<0 || n>100) {
            printf("so luong phan tu khong hop le\n");
        }
    }while (n<0 || n>100);
    inputArray(arr, n);
    do {
        printf("Nhap vi tri muon xoa:");
        scanf("%d", &position);
        if (position > n-1 || position < 0) {
            printf("vi tri khong ton tai\n");
        }
    } while (position > n-1 || position < 0);

    delete(arr, n, position);

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
}