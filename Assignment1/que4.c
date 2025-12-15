#include <stdio.h>


int findNthOccurrence(int arr[], int size, int target, int n) {
    int count = 0; 

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++; 

            if (count == n) {
                return i; 
            }
        }
    }

    return -1;
}

int main() {
    // Example array (you can modify this)
    int array[] = {10, 20, 30, 20, 40, 20, 50};
    int size = sizeof(array) / sizeof(array[0]);
    int target_element, occurrence_n;
    int result_index;

    printf("Array: {10, 20, 30, 20, 40, 20, 50}\n");

    // Get target element from the user
    printf("Enter the element to find: ");
    scanf("%d", &target_element);

    // Get the occurrence number 'n' from the user
    printf("Enter the occurrence number (n): ");
    scanf("%d", &occurrence_n);

    // Call the function to find the nth occurrence
    result_index = findNthOccurrence(array, size, target_element, occurrence_n);

    // Display the result
    if (result_index != -1) {
        printf("The %d%s occurrence of %d is at index: %d\n", 
               occurrence_n, 
               (occurrence_n % 10 == 1 && occurrence_n % 100 != 11) ? "st" : 
               (occurrence_n % 10 == 2 && occurrence_n % 100 != 12) ? "nd" : 
               (occurrence_n % 10 == 3 && occurrence_n % 100 != 13) ? "rd" : "th",
               target_element, 
               result_index);
    } else {
        printf("-1.\n");
    }

    return 0;
}
