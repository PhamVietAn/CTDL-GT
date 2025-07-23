#include <stdio.h>


void addEdge(int graph[3][3], int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

void printGraph(int graph[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[3][3] = {0};

    int firstNode = 1;
    int secondNode = 2;

    addEdge(graph, firstNode, secondNode);

    printf("Ma tran ke sau khi them canh:\n");
    printGraph(graph);

    return 0;
}
