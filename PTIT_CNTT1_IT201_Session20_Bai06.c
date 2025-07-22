//
// Created by ADMIN on 22/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct Queue {
    Node** data;
    int cap;
    int front;
    int rear;
}Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Node**)malloc(size * sizeof(Node*));
    queue->cap = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void enQueue(Queue* queue, Node* node) {
    if (queue->rear == queue->cap - 1) {
        printf("Queue is full\n");
        return;
    }

    queue->data[++queue->rear] = node;
}

Node* deQueue(Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue is empty\n");
        return;
    }
    return queue->data[queue->front++];
}

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

int levelOderBFS(Node* root, int key) {
    if (root == NULL) {
        return -1;
    }

    Queue* queue = createQueue(100);
    enQueue(queue, root);
    int level = 1;

    while (!isEmpty(queue)) {
        printf("%d ", queue->rear);
        printf("%d ", queue->front);
        int levelSize = queue->rear - queue->front + 1;

        for (int i = 0; i < levelSize; i++) {
            Node* node = deQueue(queue);
            if (node->data == key) {
                return level;
            }

            if (node->left != NULL) {
                enQueue(queue, node->left);
            }
            if (node->right != NULL) {
                enQueue(queue, node->right);
            }
        }
        level++;
    }

    return -1;
}

int main() {
    Node* root = NULL;
    root = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;

     printf("Node level: %d", levelOderBFS(root, 1));
}