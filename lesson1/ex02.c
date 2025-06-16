#include <stdio.h>;

void printDouble(int n) {
    int i = 1;
    while(i < n) {
        printf("%d\n", i)
        i *= 2;
    }
}

//độ phức tạp thời gian (Time complexity) của đoạn mã: O(log n)