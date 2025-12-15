#include <stdio.h>
#include <stdlib.h> 


struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (!stack) return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        free(stack);
        return NULL;
    }
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1; 
    return stack->array[stack->top--];
}

void reverseArray(int arr[], int n) {
    // 1. Create a stack of size n
    struct Stack* stack = createStack(n);
    if (!stack) return;

    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }

    // 4. Free allocated memory
    free(stack->array);
    free(stack);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Reversed array: ");
    printArray(arr, n);

    return 0;
}
