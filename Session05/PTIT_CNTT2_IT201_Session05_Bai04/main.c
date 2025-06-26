#include <stdio.h>

int sumNum(int a, int b) {
    if (a == b) {
        return a;
    } else {
        return a + (sumNum(a+1,b));
    }
}

int main(void) {
    int first, second;

    printf("Enter a first number: ");
    scanf("%d", &first);
    printf("Enter a second number: ");
    scanf("%d", &second);

    if (first<0 || second<0) {
        printf("Khong hop le");
        return 0;
    }

    int sum = sumNum(first, second);
    printf("%d\n", sum);
    return 0;
}