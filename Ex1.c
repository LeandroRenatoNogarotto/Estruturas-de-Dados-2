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

Node* removeNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMinNode(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);
    }

    return root;
}

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->value);
        printInOrder(root->right);
    }
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

    printf("In-order traversal of the tree: \n");
    printInOrder(root);
    printf("\n");

    printf("Searching for value 50: \n");
    Node* foundNode = searchNode(root, 50);
    if (foundNode != NULL) {
        printf("Found value %d\n", foundNode->value);
    } else {
        printf("Value not found\n");
    }

    printf("Removing value 50\n");
    root = removeNode(root, 50);

    printf("In-order traversal of the tree after removal: ");
    printInOrder(root);
    printf("\n");

    return 0;
}
