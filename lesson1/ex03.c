#include <stdio.h>;

int* mallocArray(int n) {
    int* arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

//độ phức tạp không gian (Space complexity) của đoạn mã: O(n)