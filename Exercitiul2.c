#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

bool isBST(Node* root, long min, long max) {
    if (root == NULL) {
        return true;
    }

    if (root->data <= min || root->data >= max) {
        return false;
    }

    return isBST(root->left, min, root->data) && 
           isBST(root->right, root->data, max);
}

void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    Node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15);

    printf("CERINTA 2: Verificare Binary Search Tree (BST)\n");
    printf("Parcurgere In-ordine: ");
    printInorder(root);
    printf("\n");

    if (isBST(root, LONG_MIN, LONG_MAX)) {
        printf("Rezultat: Arborele ESTE un Binary Search Tree valid.\n");
    } else {
        printf("Rezultat: Arborele NU este un Binary Search Tree valid.\n");
    }

    root->left->right->data = 25;
    printf("\nTest dupa modificare gresita (nodul 15 devine 25):");
    if (isBST(root, LONG_MIN, LONG_MAX)) {
        printf("\nRezultat: Este BST.\n");
    } else {
        printf("\nRezultat: NU mai este BST (25 nu poate sta in stanga lui 20).\n");
    }

    return 0;
}