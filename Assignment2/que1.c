#include <stdio.h>

void insertionSortDescending(int arr[], int n) {
    int i, key, j;
    // Iterate from the second element to the last
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test the function
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    insertionSortDescending(arr, n);

    printf("Sorted array in descending order: \n");
    printArray(arr, n);

    return 0;
}
