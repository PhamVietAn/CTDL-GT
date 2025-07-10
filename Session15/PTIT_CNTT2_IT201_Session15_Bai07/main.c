#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 30
#define MAX_QUEUE 100

typedef struct {
    char name[MAX_NAME + 1];
} Customer;

typedef struct {
    Customer queue[MAX_QUEUE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

int isFull(Queue* q) {
    return q->rear == MAX_QUEUE - 1;
}

void addCustomer(Queue* q) {
    if (isFull(q)) {
        printf("Hang doi da day, khong the them khach moi!\n");
        return;
    }

    Customer c;
    printf("Nhap ten khach hang: ");
    scanf(" %[^\n]", c.name);

    q->rear++;
    q->queue[q->rear] = c;

    printf("Da them khach \"%s\" vao hang doi.\n", c.name);
}

void serveCustomer(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
        return;
    }

    Customer c = q->queue[q->front];
    printf("Dang phuc vu khach: %s\n", c.name);
    q->front++;

    if (q->front > q->rear) {
        initQueue(q);
    }
}

void showQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Khong co khach nao trong hang doi.\n");
        return;
    }

    printf("Danh sach khach hang dang cho:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d. %s\n", i - q->front + 1, q->queue[i].name);
    }
}

void menu() {
    printf("\n==== QUAY BAN VE ====\n");
    printf("1. Them khach hang vao hang doi\n");
    printf("2. Phuc vu khach hang\n");
    printf("3. Hien thi danh sach khach dang cho\n");
    printf("4. Thoat chuong trinh\n");
    printf("Chon: ");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCustomer(&q); break;
            case 2: serveCustomer(&q); break;
            case 3: showQueue(&q); break;
            case 4: printf("Tam biet!\n"); break;
            default: printf("Lua chon khong hop le.\n"); break;
        }

    } while (choice != 4);

    return 0;
}
