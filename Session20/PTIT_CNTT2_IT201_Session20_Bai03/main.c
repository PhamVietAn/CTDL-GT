#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

QueueNode* createQueueNode(Node* treeNode) {
    QueueNode* qNode = (QueueNode*)malloc(sizeof(QueueNode));
    qNode->treeNode = treeNode;
    qNode->next = NULL;
    return qNode;
}

void enqueue(QueueNode** front, QueueNode** rear, Node* treeNode) {
    QueueNode* temp = createQueueNode(treeNode);
    if (*rear == NULL) {
        *front = *rear = temp;
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }
}

Node* dequeue(QueueNode** front, QueueNode** rear) {
    if (*front == NULL) return NULL;
    QueueNode* temp = *front;
    Node* treeNode = temp->treeNode;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return treeNode;
}

void addNode(Node* root, int value) {
    if (root == NULL) return;

    QueueNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (front != NULL) {
        Node* current = dequeue(&front, &rear);

        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            enqueue(&front, &rear, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            enqueue(&front, &rear, current->right);
        }
    }
}

// Duyệt theo level
void levelOrder(Node* root) {
    if (root == NULL) return;
    QueueNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);
    while (front != NULL) {
        Node* current = dequeue(&front, &rear);
        printf("%d ", current->data);
        if (current->left != NULL) enqueue(&front, &rear, current->left);
        if (current->right != NULL) enqueue(&front, &rear, current->right);
    }
}

int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Cay truoc khi them: ");
    levelOrder(root);
    printf("\n");

    int addValue;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &addValue);

    addNode(root, addValue);

    printf("Cay sau khi them: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
