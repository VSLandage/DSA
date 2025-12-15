#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
       
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev; 
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// (Use the 'push' function from the first example to build the list)
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Driver program to test the iterative reversal
int main() {
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original list: ");
    printList(head); // Output: 1 2 3 4

    head = reverseList(head);

    printf("Reversed list (printed normally after reversal): ");
    printList(head); // Output: 4 3 2 1

    return 0;
}
