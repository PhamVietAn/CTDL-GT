#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}

int main () {
    int n;
    int *arr = (int*)malloc(sizeof(int)*n);

    if (arr==NULL) {
        printf("khong the cap phat bo nho\n");
        return 1;
    }

    do{
        printf("nhap so luong phan tu co trong mang (0<n<100): ");
        scanf("%d", &n);
        if (n<0 || n>100) {
            printf("so luong phan tu khong hop le\n");
        }
    }while (n<0 || n>100);

    inputArray(arr, n);

    for (int i = 0; i < n; i++) {
        int satisfy = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                satisfy = 0;
                break;
            }
        }
        if (satisfy) {
            printf("%d ", arr[i]);
        }
    }

    free(arr);
}