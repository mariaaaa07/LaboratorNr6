#include <stdio.h>
#include <stdlib.h>

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

Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = findLCA(root->left, n1, n2);

    Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

void printPostorder(Node* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);
    root->right->left = createNode(0);
    root->right->right = createNode(8);

    int v1 = 5, v2 = 1;
    Node* lca1 = findLCA(root, v1, v2);
    
    int v3 = 6, v4 = 4;
    Node* lca2 = findLCA(root, v3, v4);

    printf("CERINTA 3: Cel mai apropiat stramos comun (LCA)\n");
    printf("Parcurgere Post-ordine: ");
    printPostorder(root);
    printf("\n\n");

    printf("LCA pentru %d si %d este: %d\n", v1, v2, lca1->data); // Ar trebui să fie 3
    printf("LCA pentru %d si %d este: %d\n", v3, v4, lca2->data); // Ar trebui să fie 5

    return 0;
}