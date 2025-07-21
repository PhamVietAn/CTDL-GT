#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char drinkName[50];
    float price;
    char size;
} DrinkOrder;

typedef struct {
    DrinkOrder data[MAX];
    int front, rear;
} Queue;

typedef struct {
    DrinkOrder data[MAX];
    int top;
} Stack;

Queue orderQueue;
Stack cancelStack;

void initQueue() {
    orderQueue.front = orderQueue.rear = -1;
}

void initStack() {
    cancelStack.top = -1;
}

int isQueueEmpty() {
    return orderQueue.front == -1;
}

int isQueueFull() {
    return (orderQueue.rear + 1) % MAX == orderQueue.front;
}

void enqueue(DrinkOrder d) {
    if (isQueueFull()) {
        printf("Hang doi day!\n");
        return;
    }
    if (isQueueEmpty())
        orderQueue.front = orderQueue.rear = 0;
    else
        orderQueue.rear = (orderQueue.rear + 1) % MAX;
    orderQueue.data[orderQueue.rear] = d;
}

DrinkOrder dequeue() {
    DrinkOrder d = orderQueue.data[orderQueue.front];
    if (orderQueue.front == orderQueue.rear)
        orderQueue.front = orderQueue.rear = -1;
    else
        orderQueue.front = (orderQueue.front + 1) % MAX;
    return d;
}

void push(DrinkOrder d) {
    if (cancelStack.top == MAX - 1) {
        printf("Stack day!\n");
        return;
    }
    cancelStack.data[++cancelStack.top] = d;
}

DrinkOrder pop() {
    return cancelStack.data[cancelStack.top--];
}

void order() {
    DrinkOrder d;
    printf("Nhap ten do uong: "); fflush(stdin); gets(d.drinkName);
    printf("Nhap gia: "); scanf("%f", &d.price);
    printf("Nhap size (S/M/L): "); scanf(" %c", &d.size);
    enqueue(d);
    printf("Da goi mon thanh cong!\n");
}

void cancel() {
    if (isQueueEmpty()) {
        printf("Khong co mon nao de huy!\n");
        return;
    }
    DrinkOrder d = dequeue();
    push(d);
    printf("Da huy mon: %s\n", d.drinkName);
}

void reorder() {
    if (cancelStack.top == -1) {
        printf("Khong co mon nao trong danh sach huy!\n");
        return;
    }
    DrinkOrder d = pop();
    enqueue(d);
    printf("Da dat lai mon: %s\n", d.drinkName);
}

void viewOrders() {
    if (isQueueEmpty()) {
        printf("Khong co mon nao dang cho!\n");
        return;
    }
    int i = orderQueue.front;
    printf("Danh sach mon dang cho:\n");
    while (1) {
        DrinkOrder d = orderQueue.data[i];
        printf("Ten: %s | Gia: %.2f | Size: %c\n", d.drinkName, d.price, d.size);
        if (i == orderQueue.rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;
    initQueue();
    initStack();
    do {
        printf("\n————— MENU COFFEE —————\n");
        printf("1. ORDER\n2. CANCEL\n3. REORDER\n4. VIEW ORDERS\n5. EXIT\nChon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: order(); break;
            case 2: cancel(); break;
            case 3: reorder(); break;
            case 4: viewOrders(); break;
            case 5: printf("Thoat chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 5);
    return 0;
}
