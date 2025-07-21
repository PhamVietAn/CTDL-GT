#include <stdio.h>
int G(int n) { if (n == 0) return 1; return 2 * G(n - 1); }
int main(void) {
    printf("Hello, World!\n");
    printf("%d\n", G(3));
    return 0;
}