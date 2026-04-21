#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void serialize(Node* root, char* str) {
    if (root == NULL) {
        strcat(str, "#,"); 
        return;
    }

    char buf[20];
    sprintf(buf, "%d,", root->data);
    strcat(str, buf);

   
    serialize(root->left, str);
    serialize(root->right, str);
}

Node* deserializeHelper(char** strPtr) {
    char* token = strtok(*strPtr, ",");
    *strPtr = NULL; 

    if (token == NULL || strcmp(token, "#") == 0) {
        return NULL;
    }

    Node* root = createNode(atoi(token));

    root->left = deserializeHelper(strPtr);
    root->right = deserializeHelper(strPtr);

    return root;
}

void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {

    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->right = createNode(8);

    printf("--- EXERCITIUL 4: Serializare si Deserializare ---\n");


    char buffer[200] = ""; 
    serialize(root, buffer);
    printf("Arborele sub forma de string: %s\n", buffer);

  
    char* tempStr = strdup(buffer); 
    char* ptr = tempStr;
    Node* reconstructedRoot = deserializeHelper(&ptr);

    printf("Arborele reconstruit (afisat In-ordine): ");
    printInorder(reconstructedRoot);
    printf("\n");

    free(tempStr);
    return 0;
}