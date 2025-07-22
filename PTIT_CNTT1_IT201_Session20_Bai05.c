//
// Created by ADMIN on 22/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int find_Max(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int maxleft = find_Max(root->left);
    int maxright = find_Max(root->right);

    int max = root->data;
    if (maxleft > max) {
        max = maxleft;
    }
    if (maxright > max) {
        max = maxright;
    }

    return max;
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

    printf("max value: %d ", find_Max(root));
}