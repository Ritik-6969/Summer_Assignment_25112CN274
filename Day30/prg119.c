#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

void addEmployee(struct Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Maximum reached.\n");
        return;
    }

    struct Employee emp;
    printf("Enter employee id: ");
    scanf("%d", &emp.id);
    getchar();

    printf("Enter employee name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Enter department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = '\0';

    printf("Enter salary: ");
    scanf("%f", &emp.salary);
    getchar();

    employees[*count] = emp;
    (*count)++;
    printf("Employee added successfully.\n");
}

void displayAllEmployees(const struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n%-8s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-8d %-20s %-15s %-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

int findEmployeeIndex(const struct Employee employees[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void searchEmployee(const struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees found.\n");
        return;
    }

    int id;
    printf("Enter employee id to search: ");
    scanf("%d", &id);
    getchar();

    int index = findEmployeeIndex(employees, count, id);
    if (index == -1) {
        printf("Employee with id %d not found.\n", id);
    } else {
        printf("\nEmployee details:\n");
        printf("ID         : %d\n", employees[index].id);
        printf("Name       : %s\n", employees[index].name);
        printf("Department : %s\n", employees[index].department);
        printf("Salary     : %.2f\n", employees[index].salary);
    }
}

void updateEmployee(struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to update.\n");
        return;
    }

    int id;
    printf("Enter employee id to update: ");
    scanf("%d", &id);
    getchar();

    int index = findEmployeeIndex(employees, count, id);
    if (index == -1) {
        printf("Employee with id %d not found.\n", id);
        return;
    }

    printf("Enter new name (leave empty to keep current): ");
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(employees[index].name, buffer, sizeof(employees[index].name));
        employees[index].name[sizeof(employees[index].name) - 1] = '\0';
    }

    printf("Enter new department (leave empty to keep current): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(employees[index].department, buffer, sizeof(employees[index].department));
        employees[index].department[sizeof(employees[index].department) - 1] = '\0';
    }

    printf("Enter new salary (enter 0 to keep current): ");
    float salary;
    scanf("%f", &salary);
    getchar();
    if (salary != 0.0f) {
        employees[index].salary = salary;
    }

    printf("Employee updated successfully.\n");
}

void deleteEmployee(struct Employee employees[], int *count) {
    if (*count == 0) {
        printf("No employees to delete.\n");
        return;
    }

    int id;
    printf("Enter employee id to delete: ");
    scanf("%d", &id);
    getchar();

    int index = findEmployeeIndex(employees, *count, id);
    if (index == -1) {
        printf("Employee with id %d not found.\n", id);
        return;
    }

    for (int i = index; i < *count - 1; ++i) {
        employees[i] = employees[i + 1];
    }
    (*count)--;
    printf("Employee deleted successfully.\n");
}

int main(void) {
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do {
        printf("\nMini Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addEmployee(employees, &employeeCount);
                break;
            case 2:
                displayAllEmployees(employees, employeeCount);
                break;
            case 3:
                searchEmployee(employees, employeeCount);
                break;
            case 4:
                updateEmployee(employees, employeeCount);
                break;
            case 5:
                deleteEmployee(employees, &employeeCount);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please choose 1-6.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
