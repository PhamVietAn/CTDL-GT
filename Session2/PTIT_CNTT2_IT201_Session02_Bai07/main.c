#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}



int main () {
    int *arr;
    int n, val;
    int found = 0;

    arr = (int*)malloc(sizeof(int)*n);
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

    printf("Nhap phan tu bat ki:");
    scanf("%d", &val);

    for (int i = 0; i < n - 1  && !found; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (arr[i] + arr[j] == val) {
                printf("%d, %d", arr[i], arr[j]);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("khong tim thay");
    }
    free(arr);
}