#include <stdio.h>

int countWay(int n) {
    if (n<=0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }
    if (n==2) {
        return 2;
    }
    return countWay(n-1) + countWay(n-2);
}

int main(void) {
    int n;

    printf("nhap vao so bac cua cau thang");
    scanf("%d", &n);

    if (n<1) {
        printf("So bac khong hop le");
    } else {
        int result = countWay(n);
        printf("Co tong cong %d cach de leo het %d bac\n", result, n);
    }
    return 0;
}