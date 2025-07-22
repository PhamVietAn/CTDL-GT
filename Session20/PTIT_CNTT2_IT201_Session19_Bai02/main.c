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

// Duyệt NLR - Preorder
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Duyệt LNR - Inorder
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Duyệt LRN - Postorder
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Duyệt theo level - Level Order Traversal
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

    printf("Duyet NLR (Preorder): ");
    preOrder(root);
    printf("\n");

    printf("Duyet LNR (Inorder): ");
    inOrder(root);
    printf("\n");

    printf("Duyet LRN (Postorder): ");
    postOrder(root);
    printf("\n");

    printf("Duyet theo Level: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
