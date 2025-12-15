#include <stdio.h>

int firstNonRepeating(int arr[], int n) {
    for (int i = 0; i < n; i++) { 
        int j;
        for (j = 0; j < n; j++) {  
            if (i != j && arr[i] == arr[j]) {
                break; 
            }
        }
        if (j == n) {
            return arr[i]; 
        }
    }
    return -1; 
}

int main() {
    
    int arr[] = {1, 2, 3, -1, 2, 1, 0, 4, -1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = firstNonRepeating(arr, n);

    if (result != -1) {
        printf("The first non-repeating element is: %d\n", result);
    } else {
        printf("No non-repeating element found.\n");
    }

    return 0;
}
