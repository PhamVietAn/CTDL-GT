#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("So luong khong hop le");
    }
    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int found = 0;
    for(int i = 0; i < n / 2; i++) {
        if(arr[i] == arr[n - i - 1]) {
            printf("(%d,%d)", arr[i], arr[n - i - 1]);
            found = 1;
        }
    }
    if (found == 0) {
        printf("Khong tim thay cap doi xung");
    }

    return 0;
}