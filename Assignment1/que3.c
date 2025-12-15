#include <stdio.h>

int binarySearchDesc(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    
    return -1;
}

int main() {
    int arr[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    int result = binarySearchDesc(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Another example
    target = 99;
    result = binarySearchDesc(arr, 0, n - 1, target);
     if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
