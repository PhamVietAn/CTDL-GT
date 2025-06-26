#include <stdio.h>

int sumNum(int n) {
    if (n == 1) {
        return 1;
    } else if (n==0){
        return n=1;
    }else {
        return n * sumNum(n - 1);
    }
}

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n<0) {
        printf("Khong hop le");
        return 0;
    }

    int sum = sumNum(n);
    printf("%d\n", sum);
    return 0;
}