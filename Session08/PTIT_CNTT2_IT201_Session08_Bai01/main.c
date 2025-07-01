#include <stdio.h>
#include <stdlib.h>

int linerSearch(int arr[], int n, int x, int index) {
    if (index >= n) {
        return -1;
    }
    if (arr[index] == x) {
        return index;
    }
    return linerSearch(arr, n, x, index + 1);
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

    int result = linerSearch(arr, n, search, 0);

    if (result == -1) {
        printf("Khong tim thay");
    } else {
        printf("Vi tri thu %d", result);
    }
    free(arr);

    return 0;
}