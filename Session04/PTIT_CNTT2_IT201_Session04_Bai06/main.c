#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
} student;

int main(void) {
    student st[5];
    int i;

    printf("Nhap thong tin cho 5 sinh vien\n");
    for (i = 0; i < 5; i++) {
        printf("\nNhap thong tin sinh vien %d\n", i+1);

        printf("ID: ");
        scanf("%d", &st[i].id);
        getchar();

        printf("Name: ");
        fgets(st[i].name, 20, stdin);
        getchar();

        printf("Age: ");
        scanf("%d", &st[i].age);
        getchar();
    }

    int findID, check = -1;
    printf("Nhap ID can tim kiem: ");
    scanf("%d", &findID);
    for (i = 0; i < 5; i++) {
        if (st[i].id == findID) {
            printf("\nTim thay sinh vien\n");
            printf("ID: %d, Name: %s, Age: %d", st[i].id, st[i].name, st[i].age);
            check = 1;
            break;
        }
    }
    if (check == -1) {
        printf("Khong tim thay sinh vien");
    }

    return 0;
}