#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *left, *right;
    int size; 
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->size = 1; 
    return newNode;
}


Node* insert(Node* node, int data) {
    if (node == NULL) return createNode(data);

    
    node->size++; 

    if (data <= node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}


int getRank(Node* root, int x) {
    int rank = 0;
    Node* current = root;

    while (current != NULL) {
        if (x == current->data) {
            // Found the element. Rank = current accumulator + size of left subtree + 1 (for current node)
            return rank + (current->left ? current->left->size : 0) + 1;
        } else if (x > current->data) {
            // x is in the right subtree. Add left subtree's size + 1 (current node) to rank accumulator
            rank += (current->left ? current->left->size : 0) + 1;
            current = current->right;
        } else {
            // x is in the left subtree. Go left.
            current = current->left;
        }
    }
    return -1; 
}


int main() {
    int stream[] = { 10, 20, 15, 3, 4, 4, 1 };
    int n = sizeof(stream) / sizeof(stream[0]);
    Node* root = NULL;

    // Process the stream and build the augmented BST
    for (int i = 0; i < n; i++) {
        root = insert(root, stream[i]);
    }

    // Get the rank of 4
    int element_to_find = 4;
    int rank_of_4 = getRank(root, element_to_find);

    if (rank_of_4 != -1) {
        printf("Input stream: { 10, 20, 15, 3, 4, 4, 1 }\n");
        printf("Rank of %d is: %d in c\n", element_to_find, rank_of_4);
    } else {
        printf("Element %d not found in the stream.\n", element_to_find);
    }


    return 0;
}


