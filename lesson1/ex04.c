#include <stdio.h>;

int sum1(int n) {
    int sum=0;
    for (int i=0; i<=n; i++) {
        sum += i;
    }
    return sum;
}
}//độ phức tạp thời gian: O(n)

int sum2(int n) {
    return n * (n+1) / 2;
}
//độ phức tạp thời gian: O(1)
