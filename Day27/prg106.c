#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

void addEmployee();
void displayAllEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
        printf("\n=================================");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Update Employee Records");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAllEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid option! Select between 1 and 6.\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addEmployee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("\nDatabase is full! Cannot add more employees.\n");
        return;
    }

    Employee new_emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &new_emp.id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == new_emp.id) {
            printf("Error: Employee ID %d already exists!\n", new_emp.id);
            return;
        }
    }

    clearInputBuffer();

    printf("Enter Full Name: ");
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = 0; 

    printf("Enter Designation: ");
    fgets(new_emp.designation, sizeof(new_emp.designation), stdin);
    new_emp.designation[strcspn(new_emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &new_emp.salary);

    employees[employee_count] = new_emp;
    employee_count++;

    printf("\nEmployee record added successfully!\n");
}

void displayAllEmployees() {
    if (employee_count == 0) {
        printf("\nNo records found to display.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------\n");
    printf("%-10s %-25s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-----------------------------------------------------------------\n");
    
    for (int i = 0; i < employee_count; i++) {
        printf("%-10d %-25s %-20s $%-9.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
    printf("-----------------------------------------------------------------\n");
}

void searchEmployee() {
    if (employee_count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int search_id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == search_id) {
            printf("\n--- Record Found ---");
            printf("\nID:          %d", employees[i].id);
            printf("\nName:        %s", employees[i].name);
            printf("\nDesignation: %s", employees[i].designation);
            printf("\nSalary:      $%.2f\n", employees[i].salary);
            return;
        }
    }
    printf("\nEmployee ID %d not found.\n", search_id);
}

void updateEmployee() {
    if (employee_count == 0) {
        printf("\nNo records available to update.\n");
        return;
    }

    int update_id;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &update_id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == update_id) {
            printf("\nCurrent Data: %s | %s | $%.2f\n", employees[i].name, employees[i].designation, employees[i].salary);
            
            clearInputBuffer();
            
            printf("\nEnter New Name (Press Enter to keep current): ");
            char temp_name[50];
            fgets(temp_name, sizeof(temp_name), stdin);
            if (temp_name[0] != '\n') {
                temp_name[strcspn(temp_name, "\n")] = 0;
                strcpy(employees[i].name, temp_name);
            }

            printf("Enter New Designation (Press Enter to keep current): ");
            char temp_des[50];
            fgets(temp_des, sizeof(temp_des), stdin);
            if (temp_des[0] != '\n') {
                temp_des[strcspn(temp_des, "\n")] = 0;
                strcpy(employees[i].designation, temp_des);
            }

            printf("Enter New Salary (Enter 0 or negative to keep current): ");
            float temp_salary;
            scanf("%f", &temp_salary);
            if (temp_salary > 0) {
                employees[i].salary = temp_salary;
            }

            printf("\nEmployee records updated successfully!\n");
            return;
        }
    }
    printf("\nEmployee ID %d not found.\n", update_id);
}

void deleteEmployee() {
    if (employee_count == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int delete_id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &delete_id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == delete_id) {
            for (int j = i; j < employee_count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employee_count--; 
            printf("\nEmployee record deleted successfully!\n");
            return;
        }
    }
    printf("\nEmployee ID %d not found.\n", delete_id);
}
