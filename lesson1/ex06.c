#include <stdio.h>

ỉnt countOccurrences(int arr[], int n, int element) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

/*
 * độ phức tạp thời gian: O(n)
 * độ phức tạp không gian: O(1)
 */