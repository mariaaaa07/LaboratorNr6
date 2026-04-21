#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int getHeight(Node* root) {
    if (!root) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return 1 + (lh > rh ? lh : rh);
}

bool isBalanced(Node* root) {
    if (!root) return true;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }
    return false;
}

void printPreorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);

    printf(" -Verificare Arbore Echilibrat-\n");
    printf("Parcurgere Pre-ordine: ");
    printPreorder(root);
    
    if (isBalanced(root)) {
        printf("\nRezultat: Arborele este ECHILIBRAT.\n");
    } else {
        printf("\nRezultat: Arborele NU este echilibrat.\n");
    }

    return 0;
}