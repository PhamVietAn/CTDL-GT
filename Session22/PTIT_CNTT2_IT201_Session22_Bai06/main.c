#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int v, e;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void DFS(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < v; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            DFS(i);
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
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(start);
    printf("\n");

    return 0;
}
