#include <stdio.h>

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void add(int arr[], int n, int pos, int val) {
    for (int i = n-1; i >= pos; i-- ) {
        arr[i+1] = arr[i];
    }
    arr[pos] = val;
    ++n;
}

int main () {
    int arr[100];
    int n, position, val;

    do{
        printf("nhap so luong phan tu co trong mang (0<n<100): ");
        scanf("%d", &n);
        if (n<0 || n>100) {
            printf("so luong phan tu khong hop le\n");
        }
    }while (n<0 || n>100);
    inputArray(arr, n);
    do {
        printf("Nhap vi tri muon them:");
        scanf("%d", &position);
        if (position > n || position < 0) {
            printf("vi tri khong ton tai\n");
        }
    } while (position > n || position < 0);

    printf("Nhap phan tu muon them:");
    scanf("%d", &val);

    add(arr, n, position, val);

    for (int i = 0; i < n + 1 ; i++) {
        printf("%d ", arr[i]);
    }
}