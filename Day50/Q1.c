#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main() {
    struct Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);

    int key = 40;
    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element %d found in the BST.\n", result->data);
    else
        printf("Element %d not found.\n", key);

    return 0;
}