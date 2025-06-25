#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Nhap so luong phan tu: \n");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    int num;
    printf("Nhap phan tu muon kiem tra: \n");
    scanf("%d", &num);

    int start = 0, end = n - 1, check = 0;

    while (start <= end) {
        int mid = (end + start) / 2;
        if (arr[mid] == num) {
            check = 1;
            break;
        }
        if (arr[mid] > num) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if (check == 1) {
        printf("Phan tu co trong mang \n");
    } else {
        printf("Phan tu khong co trong mang \n");
    }

    free(arr);
    return 0;
}