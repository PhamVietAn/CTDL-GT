#include <stdio.h>

int findMax(int arr[], int n, int i) {
    if (i==n-1) {
        return arr[i];
    }
    int max = findMax(arr, n, i + 1);
    return (arr[i] > max) ? arr[i] : max;
}

int findMin(int arr[], int n, int i) {
    if (i==n-1) {
        return arr[i];
    }
    int min = findMin(arr, n, i + 1);
    return (arr[i] < min) ? arr[i] : min;
}

int main(void) {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d] =  ",i);
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, n, 0);
    printf("Max trong mang = %d\n", max);
    int min = findMin(arr, n, 0);
    printf("Min trong mang = %d\n", min);

    return 0;
}