#include <stdio.h>

int tinhSoDuongDi(int n, int m) {
    if (n == 1 || m == 1) return 1;
    return tinhSoDuongDi(n - 1, m) + tinhSoDuongDi(n, m - 1);
}

int main(void) {
    int rows, cols;
    printf("Nhap vao so hang: ");
    scanf("%d", &rows);

    printf("Nhap vao so cot: ");
    scanf("%d", &cols);

    if (rows < 1 || cols < 1) {
        printf("khong hop le");
        return 1;
    }

    int totalPaths = tinhSoDuongDi(rows,cols);

    printf("\nInput: (%d,%d)\n",rows,cols);
    printf("Output: %d\n", totalPaths);

    return 0;
}