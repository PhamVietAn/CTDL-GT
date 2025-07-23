#include <stdio.h>

void addEdge(int graph[4][4], int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

void printGraph(int graph[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[4][4] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("Ma tran ke cua do thi:\n");
    printGraph(graph);

    return 0;
}
