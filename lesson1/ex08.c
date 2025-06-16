#include <stdio.h>

int findMostFrequent(int arr[], int size) {
    int maxCount = 0;
    int mostFrequentCount = arr[0];

    for (int i = 1; i < size; i++) {
        int count = 0;
        for (int j = i +1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequentCount = arr[i];
        }
    }
    return mostFrequentCount;
}

/*
 * độ phức tạp tời gian: O(n^2)
 * độ phức tạp không gian: O(1)
 */
