#include <stdio.h>
#define MAX 5

typedef struct {
    int array[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

Queue initQueue(int size) {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.capacity = size;
    return q;
}

void printQueue(Queue* q) {
    printf("queue = {\n");
    printf("  array = [");
    for (int i = 0; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n");
    printf("  front = %d,\n", q->front);
    printf("  rear = %d,\n", q->rear);
    printf("  capacity = %d\n", q->capacity);
    printf("}\n");
}

int main(void) {
    int size;
    printf("Nhap kich thuoc hang doi (toi da %d): ", MAX);
    scanf("%d", &size);

    if (size > MAX || size <= 0) {
        printf("Kich thuoc khong hop le!\n");
        return 1;
    }

    Queue q = initQueue(size);
    printQueue(&q);

    return 0;
}
