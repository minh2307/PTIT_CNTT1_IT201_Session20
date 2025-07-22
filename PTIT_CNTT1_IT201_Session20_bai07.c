//
// Created by ADMIN on 22/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct Queue {
    Node** data;
    int front, rear, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->data = (Node**)malloc(sizeof(Node*) * capacity);
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < q->capacity) {
        q->data[q->rear++] = node;
    }
}

Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

void BFS(Node* root) {
    if (root == NULL) return;
    Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* node = dequeue(q);
        printf("%d ", node->data);
        if (node->left) enqueue(q, node->left);
        if (node->right) enqueue(q, node->right);
    }
    free(q->data);
    free(q);
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        printf("Cay rong!\n");
        return NULL;
    }

    Queue* q = createQueue(100);
    enqueue(q, root);

    Node* target = NULL;
    Node* lastNode = NULL;
    Node* lastParent = NULL;

    while (!isEmpty(q)) {
        Node* node = dequeue(q);
        if (node->data == data) {
            target = node;
        }
        if (node->left) {
            enqueue(q, node->left);
            lastParent = node;
            lastNode = node->left;
        }
        if (node->right) {
            enqueue(q, node->right);
            lastParent = node;
            lastNode = node->right;
        }
    }

    if (target == NULL) {
        printf("Khong tim thay phan tu %d trong cay.\n", data);
        free(q->data);
        free(q);
        return root;
    }

    if (lastNode == NULL || lastNode == root) {
        free(root);
        free(q->data);
        free(q);
        return NULL;
    }

    target->data = lastNode->data;

    if (lastParent->left == lastNode) {
        lastParent->left = NULL;
    } else if (lastParent->right == lastNode) {
        lastParent->right = NULL;
    }

    free(lastNode);
    free(q->data);
    free(q);

    return root;
}

int main() {
    // Khởi tạo cây
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Cay truoc khi xoa (BFS): ");
    BFS(root);
    printf("\n");

    int choice;
    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &choice);

    root = deleteNode(root, choice);

    printf("Cay sau khi xoa (BFS): ");
    BFS(root);
    printf("\n");

    return 0;
}
