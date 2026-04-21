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


int findLevelAndParent(Node* root, int val, Node** parent, int d) {
    if (root == NULL) return 0;


    if ((root->left && root->left->data == val) || 
        (root->right && root->right->data == val)) {
        *parent = root;
        return d + 1;
    }


    int leftLvl = findLevelAndParent(root->left, val, parent, d + 1);
    if (leftLvl != 0) return leftLvl;


    return findLevelAndParent(root->right, val, parent, d + 1);
}

bool areCousins(Node* root, int x, int y) {
    Node *parentX = NULL, *parentY = NULL;
    
    int levelX = findLevelAndParent(root, x, &parentX, 0);
    int levelY = findLevelAndParent(root, y, &parentY, 0);

    return (levelX != 0 && levelX == levelY && parentX != parentY);
}

void printPreorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("--- EXERCITIUL 5: Verificare Verisori ---\n");
    printf("Parcurgere Pre-ordine: ");
    printPreorder(root);
    printf("\n\n");

    int node1 = 4, node2 = 6;
    if (areCousins(root, node1, node2)) {
        printf("Nodurile %d si %d sunt VERISORI.\n", node1, node2);
    } else {
        printf("Nodurile %d si %d NU sunt verisori.\n", node1, node2);
    }

    int node3 = 4, node4 = 5;
    if (areCousins(root, node3, node4)) {
        printf("Nodurile %d si %d sunt VERISORI.\n", node3, node4);
    } else {
        printf("Nodurile %d si %d NU sunt verisori (au acelasi parinte: 2).\n", node3, node4);
    }

    return 0;
}