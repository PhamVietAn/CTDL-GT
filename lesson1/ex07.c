#include <stdio.h>

int hasDuplicate(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1; //có phần tử trùng
            }
        }
    }
    return 0; //không có phần tử trùng
}

/*
 * độ phức tạp thời gian: O(n^2)
 * độ phức tạp không gian: O(1)
 */

int hasDuplicate_array(int arr[], int n) {
    int mark[1001] = {0};
    for (int i = 0; i < n; i++) {
        if (mark[arr[i]] == 1) {
            return 1;
        }
        mark[arr[i]] = 0;
    }
    return 0;
}

/*
 * độ phức tạp thời gian: O(n)
 * độ phức tạp không gian: O(1)
 */