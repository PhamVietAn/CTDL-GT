#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int v, e;

void addEdge(int u, int w) {
    adj[u][w] = 1;
    adj[w][u] = 1;
}

void enqueue(int node) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void BFS(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = v - 1; i >= 0; i--) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(start);
    printf("\n");

    return 0;
}
