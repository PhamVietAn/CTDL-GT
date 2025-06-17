#include <stdio.h>

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

int maxValue(int arr[],int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {};
    int n;

    do{
        printf("nhap so luong phan tu co trong mang (0<n<100): ");
        scanf("%d", &n);
        if (n<0 || n>100) {
            printf("so luong phan tu khong hop le\n");
        }
    }while (n<0 || n>100);
    inputArray(arr, n);
    printf("Phan tu lon nhat: %d",maxValue(arr,n));
}