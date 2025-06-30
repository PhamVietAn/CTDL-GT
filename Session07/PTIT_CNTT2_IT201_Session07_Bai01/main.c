#include <stdio.h>

void bumbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int n;
    printf("nhap so luong phan tu trong mang: \n");
    scanf("%d", &n);
    if (n<0 || n>1000) {
        printf("khong hop le");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = \n", i);
        scanf("%d", &arr[i]);
    }

    printf("before: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bumbleSort(arr, n);

    printf("\nafter: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}