#include <stdio.h>

int printNum(int n, int a) {
    printf("%d\n", a);
    a++;
    if (a > n) {
        return 1;
    }

    printNum(n, a);

}

int main(void) {
    int n, a=1;

    printf("Enter a number: ");
    scanf("%d", &n);

    printNum(n,a);
    return 0;
}