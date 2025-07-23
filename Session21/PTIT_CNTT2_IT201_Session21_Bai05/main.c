#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int startNode, int endNode) {
    Node* newNode = createNode(endNode);
    newNode->next = graph[startNode];
    graph[startNode] = newNode;
}

void printGraph(Node* graph[]) {
    for (int i = 0; i < 3; i++) {
        printf("%d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* graph[3] = {NULL};

    int startNode, endNode;
        printf("Nhap start node (0-%d): ", 3 - 1);
        scanf("%d", &startNode);
        printf("Nhap end node (0-%d): ", 3 - 1);
        scanf("%d", &endNode);

        if (startNode >= 0 && startNode < 3 && endNode >= 0 && endNode < 3) {
            addEdge(graph, startNode, endNode);
        } else {
            printf("Node khong hop le!\n");
        }

        printf("Do thi hien tai:\n");
        printGraph(graph);

    return 0;
}
