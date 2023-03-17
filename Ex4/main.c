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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maior_ramo_aux(Node* node, int sum) {
    if (node == NULL) {
        return sum;
    }

    sum += node->value;

    if (node->left == NULL && node->right == NULL) {
        return sum;
    }

    return max(maior_ramo_aux(node->left, sum), maior_ramo_aux(node->right, sum));
}

int maior_ramo(Node* node) {
    return maior_ramo_aux(node, 0);
}

int main() {
    Node* root = NULL;

    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 20);
    insertNode(&root, 10);
    insertNode(&root, 40);
    insertNode(&root, 35);
    insertNode(&root, 45);
    insertNode(&root, 90);
    insertNode(&root, 95);

    int result = maior_ramo(root);
    printf("Maior caminho: %d\n", result);

    return 0;
}
