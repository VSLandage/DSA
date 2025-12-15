#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 

struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
    int count; 
    int capacity;
};


struct CircularQueue* createQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->capacity = MAX_SIZE;
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->count == 0);
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->count == queue->capacity);
}

// Function to add an element to the queue (enqueue)
void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = item;
    queue->count++;
    printf("Enqueued %d\n", item);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1; // Return -1 or some error indicator
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;
    return item;
}

// Function to display the elements in the queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->items[index]);
    }
    printf("\n");
}

// Main function to test the operations
int main() {
    struct CircularQueue* cq = createQueue();

    enqueue(cq, 10);
    enqueue(cq, 20);
    enqueue(cq, 30);
    enqueue(cq, 40);
    enqueue(cq, 50);

    display(cq); 

    enqueue(cq, 60); 

    printf("Dequeued element: %d\n", dequeue(cq)); 
    printf("Dequeued element: %d\n", dequeue(cq)); 

    display(cq); 

    enqueue(cq, 60);
    enqueue(cq, 70);

    display(cq); 

    free(cq); 
    return 0;
}
