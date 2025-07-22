//
// Created by ADMIN on 22/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    int n;
    Node* root = NULL;

    printf("Nhap mot so nguyen bat ki: ");
    scanf("%d", &n);

    root = createNode(n);

}