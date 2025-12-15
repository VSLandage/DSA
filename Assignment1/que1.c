#include <stdio.h>

int findLastOccurrence(int arr[], int size, int key) {
    // Start searching from the last element (size - 1) towards the first (0).
    for (int i = size - 1; i >= 0; i--) {
        // If the current element matches the key, we found the *last* one.
        if (arr[i] == key) {
            return i; // Return the index immediately.
        }
    }
    
    // If the loop finishes without returning, the key was not found.
    return -1;
}

int main() {
    int data[] = {10, 20, 30, 40, 20, 50, 20};
    int n = sizeof(data) / sizeof(data[0]); // Calculate array size
    int target = 20;
    int resultIndex;

    resultIndex = findLastOccurrence(data, n, target);

    if (resultIndex != -1) {
        printf("The last occurrence of %d is at index: %d\n", target, resultIndex);
    } else {
        printf("%d was not found in the array.\n", target);
    }

    // Example of a key not in the array
    int notFoundTarget = 99;
    resultIndex = findLastOccurrence(data, n, notFoundTarget);
    if (resultIndex == -1) {
        printf("%d was not found in the array.\n", notFoundTarget);
    }

    return 0;
}
