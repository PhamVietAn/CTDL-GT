#include <stdio.h>

int tower(int n, char a,char b,char c) {
    if (n==0) return 0;

    tower(n-1,a,c, b);
    printf("%d di chuyen tu %c sang %c\n",n,a,c);
    tower(n-1,b,a,c);
}

int main(void) {
    int n;
    char a = 'A';
    char b = 'B';
    char c = 'C';

    printf("Nhap so dia: ");
    scanf("%d",&n);

    if (n==1) {
        printf("Dia 1 di chuyen tu A sang C.\n");
        return 0;
    }

    tower(n,a,b,c);
    return 0;
}