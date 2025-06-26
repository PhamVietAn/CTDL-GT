#include <stdio.h>

int sum(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n-1] + sum(arr, n - 1);
}

int main(void) {
    int arr[50];
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if(n <= 0 || n > 50) {
        printf("Khong hop le");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ",i);
        scanf("%d", &arr[i]);
    }

    int result = sum(arr,n);
    printf("%d",result);


    return 0;
}