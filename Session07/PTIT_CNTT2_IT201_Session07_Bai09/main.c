#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void splitEvenOdd(int arr[], int n, int even[], int *evenCount, int odd[], int *oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even[(*evenCount)++] = arr[i];
        else
            odd[(*oddCount)++] = arr[i];
    }
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

int main() {
    int even[100], odd[100];
    int evenCount, oddCount;
    int n;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ",i);
        scanf("%d", &arr[i]);
    }

    n = sizeof(arr) / sizeof(arr[0]);

    splitEvenOdd(arr, n, even, &evenCount, odd, &oddCount);

    sortAscending(even, evenCount);
    sortDescending(odd, oddCount);

    int result[100];
    int total = 0;

    for (int i = 0; i < evenCount; i++) {
        result[total++] = even[i];
    }
    for (int i = 0; i < oddCount; i++) {
        result[total++] = odd[i];
    }

    printf("[");
    for (int i = 0; i < total; i++) {
        printf("%d", result[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");

    return 0;
}
