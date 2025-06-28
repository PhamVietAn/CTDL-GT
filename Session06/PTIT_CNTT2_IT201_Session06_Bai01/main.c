#include <stdio.h>

void toBinary (int n) {
    if (n > 1) {
        toBinary (n / 2);
    }
    printf("%d ", n%2);
}

int main(void) {
    int n;
    printf("Nhap so nguyen duong: \n");
    scanf("%d", &n);

    if (n==0) {
        printf("0");
    } else {
        toBinary(n);
    }
    return 0;
}