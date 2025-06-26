#include <stdio.h>

int sumNum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumNum(n - 1);
    }

}

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n<=0) {
        printf("Khong hop le");
        return 0;
    }

    int sum = sumNum(n);
    printf("%d\n", sum);
    return 0;
}