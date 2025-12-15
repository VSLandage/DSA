#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the maximum size of the queue

int arr[SIZE];
int front = 0;
int rear = 0;

// Function prototypes
void enqueue(int val);
void dequeue();
void display();
int isQueueEmpty();
int isQueueFull();

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Check if the queue is empty
int isQueueEmpty() {
    // When front and rear pointers are the same, the queue is empty
    return (front == rear);
}

// Check if the queue is full
int isQueueFull() {
    // When rear reaches the maximum size, the queue is full
    return (rear == SIZE);
}

// Add an element to the rear of the queue
void enqueue(int val) {
    if (isQueueFull()) {
        printf("Queue is Full (Overflow)\n");
    } else {
        arr[rear] = val; 
        rear++;          
        printf("Enqueued element: %d\n", val);
    }
}

// Remove an element from the front of the queue
void dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is Empty (Underflow)\n");
    } else {
        printf("Dequeued element: %d\n", arr[front]);
        front++; // Increment the front pointer
    }
}

// Display all elements in the queue
void display() {
    if (isQueueEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        // Iterate from front to rear to display elements
        for (int i = front; i < rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
