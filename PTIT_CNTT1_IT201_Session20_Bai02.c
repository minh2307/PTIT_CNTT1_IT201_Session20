//
// Created by ADMIN on 22/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void inorderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderDFS(root->left);
    printf("%d ", root->data);
    inorderDFS(root->right);
}

int main() {
    Node* root = NULL;
    root = createNode(10);
    Node* node1 = createNode(20);
    Node* node2 = createNode(30);
    Node* node3 = createNode(40);
    Node* node4 = createNode(50);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;

    inorderDFS(root);

    return 0;
}