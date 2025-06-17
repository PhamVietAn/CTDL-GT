#include <stdio.h>

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}

int countOccurences(int arr[], int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

int main () {
    int arr[] = {};
    int n;
    int value;

    do{
        printf("nhap so luong phan tu co trong mang (0<n<100): ");
        scanf("%d", &n);
        if (n<0 || n>100) {
            printf("so luong phan tu khong hop le\n");
        }
    }while (n<0 || n>100);
    inputArray(arr, n);
    printf("Nhap phan tu muon dem:");
    scanf("%d", &value);
    if (countOccurences(arr,n,value) > 0) {
        printf("%d\n",countOccurences(arr,n,value) );
    } else {
        printf("0\n");
    }

}