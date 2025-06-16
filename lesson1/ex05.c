#include <stdio.h>;

void bubbleSort(int arr[], int n) {
    for (int i=0; i<n - 1; i++) {
        for (int j=i+1; j<n - i - 1; j++) {
            if (arr[j] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
 *độ phức tạp thời gian:
 * - trường hơợp tốt nhất (mảng đã sắp xếp): O(n^2)
 * - trường hợp trung bình: O(n^2)
 * - trường hợp xấu nhất (mảng ngược): O(n^2)
 *
 * độ phức tạp không gian: O(1)
*/

