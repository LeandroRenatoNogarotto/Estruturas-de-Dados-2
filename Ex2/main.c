#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }

    if (value < (*root)->value) {
        insertNode(&(*root)->left, value);
    } else if (value > (*root)->value) {
        insertNode(&(*root)->right, value);
    }
}

Node* searchNode(Node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }

    if (value < root->value) {
        return searchNode(root->left, value);
    }

    return searchNode(root->right, value);
}

Node* findMinNode(Node* node) {
    Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* findMaxNode(Node* node) {
    Node* current = node;

    while (current && current->right != NULL) {
        current = current->right;
    }

    return current;
}

int min(Node* root) {
    if (root == NULL) {
        printf("A árvore está vazia\n");
        return -1;
    }

    Node* minNode = findMinNode(root);
    printf("Chave mínima: %d\n", minNode->value);
    return minNode->value;
}

int max(Node* root) {
    if (root == NULL) {
        printf("A árvore está vazia\n");
        return -1;
    }

    Node* maxNode = findMaxNode(root);
    printf("Chave máxima: %d\n", maxNode->value);
    return maxNode->value;
}

int main() {
    Node* root = NULL;

    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 90);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 95);
    insertNode(&root, 10);
    insertNode(&root, 35);
    insertNode(&root, 45);

    min(root);
    max(root);

    return 0;
}
