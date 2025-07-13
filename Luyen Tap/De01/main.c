#include <stdio.h>

typedef struct {
    int id;
    char title[50];
    int credits;
}Course;



void menu() {
    printf("MENU CHUC NANG:\n");
    printf("1. Them khoa hoc\n");
    printf("2. Hien thi dang sach khoa hoc\n");
    printf("3. Xoa khoa hoc\n");
    printf("4. Cap nhat thong tin khoa hoc\n");
    printf("5. Danh dau khoa hoc da hoan thanh\n");
    printf("6. Sap xep khoa hoc theo so tin chi\n");
    printf("7. Tim kiem khoa hoc theo ten\n");
    printf("8. Thoat chuong trinh\n");
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}