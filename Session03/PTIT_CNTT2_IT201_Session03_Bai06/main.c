#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n,m;

    printf("Nhap so phan tu ban dau ");
    scanf("%d",&n);

    int *arr=(int *)malloc(n*sizeof(int));

    printf("Nhap phan tu: ");
    for(int i=0;i<n;i++) {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }

    printf("Nhap so phan tu can them: ");
    scanf("%d",&m);

    int *arr2=(int *)realloc(arr, (n + m) * sizeof(int));
    arr = arr2;

    printf("Nhap phan tu them: ");
    for (int i=0;i<m;i++) {
        printf("arr2[%d]= ",n+i);
        scanf("%d",&arr2[n + i]);
    }

    for(int i=0;i<n+m;i++) {
        printf("%d ",arr[i]);
    }

    free(arr);

    return 0;
}