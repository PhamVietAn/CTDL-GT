#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30
#define MAX_QUEUE 100

typedef struct {
    char name[MAX_NAME + 1];
    int age;
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

void enqueue(Queue* q, Customer c) {
    if (isFull(q)) {
        printf("Hang doi da day.\n");
        return;
    }
    q->rear++;
    q->queue[q->rear] = c;
}

Customer dequeue(Queue* q) {
    Customer c = {"", 0};
    if (!isEmpty(q)) {
        c = q->queue[q->front];
        q->front++;
    }
    return c;
}

void addCustomer(Queue* queueOld, Queue* queueNormal) {
    Customer c;
    printf("Nhap ten: ");
    scanf(" %[^\n]", c.name);
    printf("Nhap tuoi: ");
    scanf("%d", &c.age);

    if (c.age >= 60) {
        enqueue(queueOld, c);
        printf("Da them vao hang doi nguoi gia.\n");
    } else {
        enqueue(queueNormal, c);
        printf("Da them vao hang doi binh thuong.\n");
    }
}

void serveCustomer(Queue* queueOld, Queue* queueNormal) {
    Customer c;

    if (!isEmpty(queueOld)) {
        c = dequeue(queueOld);
        printf("Dang phuc vu nguoi gia: %s (%d tuoi)\n", c.name, c.age);
    } else if (!isEmpty(queueNormal)) {
        c = dequeue(queueNormal);
        printf("Dang phuc vu khach binh thuong: %s (%d tuoi)\n", c.name, c.age);
    } else {
        printf("Khong co khach nao trong hang doi.\n");
    }
}

void showQueue(const char* title, Queue* q) {
    printf("%s:\n", title);
    if (isEmpty(q)) {
        printf("  (rong)\n");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("  %d. %s (%d tuoi)\n", i - q->front + 1, q->queue[i].name, q->queue[i].age);
        }
    }
}

void menu() {
    printf("\n==== NGAN HANG ====\n");
    printf("1. Them khach hang\n");
    printf("2. Phuc vu khach hang\n");
    printf("3. Hien thi hang doi\n");
    printf("4. Thoat\n");
    printf("Chon: ");
}

int main() {
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int choice;
    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCustomer(&queueOld, &queueNormal); break;
            case 2: serveCustomer(&queueOld, &queueNormal); break;
            case 3:
                showQueue("Hang doi nguoi gia", &queueOld);
                showQueue("Hang doi binh thuong", &queueNormal);
                break;
            case 4: printf("Tam biet!\n"); break;
            default: printf("Lua chon khong hop le.\n"); break;
        }

    } while (choice != 4);

    return 0;
}
