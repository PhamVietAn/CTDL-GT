#include <stdio.h>

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, n);

    printf("\nafter: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}