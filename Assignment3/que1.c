#include <stdio.h>
#include <stdbool.h>

#define SIZE 5 

int stack[SIZE];
int top = SIZE;


bool isEmpty();
bool isFull();
void push(int data);
int pop();
void display();

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped element: %d\n", pop());
    display();
    push(40);
    display();
    return 0;
}


bool isEmpty() {
    return top == SIZE;
}


bool isFull() {
    return top == 0;
}


void push(int data) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push element %d.\n", data);
    } else {
        // Decrement top first, then add the data to the new top position
        top--;
        stack[top] = data;
        printf("Pushed element %d onto the stack.\n", data);
    }
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1; // Return an error value
    } 
    else {
        int data = stack[top];
        top++;
        return data;
    }
}


void display() {
    printf("Stack elements (Top to Bottom):\n");
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        for (int i = top; i < SIZE; i++) {
            printf("%d\n", stack[i]);
        }
    }
}
