#include <stdio.h>

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}

int main () {
    int arr[100];
    int n, position, value;

    do{
        printf("nhap so luong phan tu co trong mang (0<n<100): ");
        scanf("%d", &n);
        if (n<0 || n>100) {
            printf("so luong phan tu khong hop le\n");
        }
    }while (n<0 || n>100);
    inputArray(arr, n);
    do {
        printf("Nhap vi tri muon sua:");
        scanf("%d", &position);
        if (position > n-1 || position < 0) {
            printf("vi tri khong ton tai\n");
        }
    } while (position > n-1 || position < 0);

    printf("gia tri muon sua: ");
    scanf("%d", &value);

    arr[position] = value;

    for (int i = 0; i < n; i++) {
        printf("arr[%d]: %d\n",i+1, arr[i]);
    }
}