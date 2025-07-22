#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Queue {
    Node** data;
    int cap;
    int front;
    int rear;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Queue* createQueue(int cap) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Node**)malloc(sizeof(Node*) * cap);
    queue->cap = cap;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isFull(Queue* queue) {
    return queue->rear == queue->cap - 1;
}

int isEmpty(Queue* queue) {
    return queue->rear < queue->front;
}

void enQueue(Queue* queue, Node* node) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->data[++queue->rear] = node;
}

Node* deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->data[queue->front++];
}

void insert(Node* root, int data) {
    Node* newNode = createNode(data);
    if (root == NULL) return;

    Queue* queue = createQueue(100);
    enQueue(queue, root);

    while (!isEmpty(queue)) {
        Node* node = deQueue(queue);

        if (node->left != NULL) {
            enQueue(queue, node->left);
        } else {
            node->left = newNode;
            break;
        }

        if (node->right != NULL) {
            enQueue(queue, node->right);
        } else {
            node->right = newNode;
            break;
        }
    }

    free(queue->data);
    free(queue);
}

void preOder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOder(root->left);
    preOder(root->right);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    insert(root, 6);
    insert(root, 7);

    preOder(root);
    printf("\n");

    return 0;
}
