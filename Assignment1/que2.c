#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

struct Employee {
    int id;
    char name[50];
    char role[50];
};

void searchById(const struct Employee employees[], int count, int searchId) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (employees[i].id == searchId) {
            printf("\nEmployee Found (ID): \n");
            printf("ID: %d, Name: %s, Role: %s\n", employees[i].id, employees[i].name, employees[i].role);
            found = true;
            break; // Exit the loop once found
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
}

void searchByName(const struct Employee employees[], int count, const char* searchName) {
    bool found = false;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].name, searchName) == 0) {
            printf("\nEmployee Found (Name): \n");
            printf("ID: %d, Name: %s, Role: %s\n", employees[i].id, employees[i].name, employees[i].role);
            found = true;
            
        }
    }
    if (!found) {
        printf("\nEmployee with name '%s' not found.\n", searchName);
    }
}


int main() {
    // 1. Create an array of employees
    struct Employee companyEmployees[] = {
        {101, "Alice Smith", "Software Engineer"},
        {102, "Bob Johnson", "Project Manager"},
        {103, "Charlie Brown", "UX Designer"},
        {104, "David Williams", "QA Tester"}
    };

    // Calculate the number of employees in the array
    int numEmployees = sizeof(companyEmployees) / sizeof(companyEmployees[0]);

    int choice;
    printf("Enter search option:\n");
    printf("1. Search by Employee ID\n");
    printf("2. Search by Employee Name (Exact Match)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int inputId;
        printf("Enter Employee ID to search: ");
        scanf("%d", &inputId);
        searchById(companyEmployees, numEmployees, inputId);
    } else if (choice == 2) {
        char inputName[50];
        printf("Enter Employee Name to search: ");

        while (getchar() != '\n'); 

        printf("Enter exact name: ");
        fgets(inputName, sizeof(inputName), stdin);
        // Remove the newline character added by fgets
        inputName[strcspn(inputName, "\n")] = 0;

        searchByName(companyEmployees, numEmployees, inputName);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
