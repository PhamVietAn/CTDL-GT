#include <stdio.h>
#include <stdlib.h>

int avgEvenNumber(int arr[], int n) {
    int count = 0;
    int sum = 0;
    int avgEvenNumber = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
            count++;
        }
    }
    avgEvenNumber = sum / count;
    printf("trung binh cong so chan: %d",avgEvenNumber);

    return;
}

int main() {
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

    avgEvenNumber(arr, n);


    free(arr);
    return 0;
}