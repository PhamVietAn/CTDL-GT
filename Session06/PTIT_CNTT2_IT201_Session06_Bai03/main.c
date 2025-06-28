#include <stdio.h>

int sumStrNum(int n) {
    if (n == 0) {
        return 0;
    }
    return  n%10 + sumStrNum(n/10);
}

int main(void) {
    int n;
    printf("Nhap so nguyen duong bat ki: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Input khong hop le");
        return 0;
    }

    int sum = sumStrNum(n);
    printf("%d", sum);
    return 0;
}