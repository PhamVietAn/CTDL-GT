#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = (int *)malloc(n*sizeof(int));

    do {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
        if(n<0 || n>1000) {
            printf("So luong phan tu khong hop le\n");
        }
    }while (n<0 || n>1000);

    for(int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}