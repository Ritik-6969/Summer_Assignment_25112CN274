#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra;          
    float da;           
    float pf;           
    float gross_salary;
    float net_salary;
};

struct Employee emp_list[MAX_EMPLOYEES];
int employee_count = 0;

void addEmployee();
void displayAllEmployees();
void searchEmployee();
void generateSalarySlip();
void calculateSalary(struct Employee *emp);

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Employee Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Generate Employee Salary Slip");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                generateSalarySlip();
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid Choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

void calculateSalary(struct Employee *emp) {
    emp->hra = emp->basic_salary * 0.20; 
    emp->da = emp->basic_salary * 0.10; 
    emp->pf = emp->basic_salary * 0.12;   
    
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    
    emp->net_salary = emp->gross_salary - emp->pf;
}

void addEmployee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("\nDatabase is full! Cannot add more employees.\n");
        return;
    }

    struct Employee new_emp;

    printf("\nEnter Employee Details:\n");
    printf("ID: ");
    scanf("%d", &new_emp.id);
    
    for (int i = 0; i < employee_count; i++) {
        if (emp_list[i].id == new_emp.id) {
            printf("Error: Employee ID %d already exists!\n", new_emp.id);
            return;
        }
    }

    printf("Name: ");
    getchar(); 
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = 0;

    printf("Designation: ");
    fgets(new_emp.designation, sizeof(new_emp.designation), stdin);
    new_emp.designation[strcspn(new_emp.designation, "\n")] = 0;

    printf("Basic Salary ($): ");
    scanf("%f", &new_emp.basic_salary);

    calculateSalary(&new_emp);

    emp_list[employee_count] = new_emp;
    employee_count++;

    printf("\nEmployee added successfully!\n");
}

void displayAllEmployees() {
    if (employee_count == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    printf("\n----------------------------------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-15s %-15s", "ID", "Name", "Designation", "Gross Salary", "Net Salary");
    printf("\n----------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < employee_count; i++) {
        printf("%-10d %-20s %-15s %-15.2f %-15.2f\n", 
               emp_list[i].id, 
               emp_list[i].name, 
               emp_list[i].designation, 
               emp_list[i].gross_salary, 
               emp_list[i].net_salary);
    }
    printf("----------------------------------------------------------------------------------------\n");
}

void searchEmployee() {
    if (employee_count == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    int search_id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < employee_count; i++) {
        if (emp_list[i].id == search_id) {
            found = 1;
            printf("\n--- Record Found ---");
            printf("\nID: %d", emp_list[i].id);
            printf("\nName: %s", emp_list[i].name);
            printf("\nDesignation: %s", emp_list[i].designation);
            printf("\nBasic Salary: $%.2f", emp_list[i].basic_salary);
            printf("\nGross Salary: $%.2f", emp_list[i].gross_salary);
            printf("\nNet Take-Home Salary: $%.2f\n", emp_list[i].net_salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }
}

void generateSalarySlip() {
    if (employee_count == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    int search_id, found = 0;
    printf("\nEnter Employee ID to generate payslip: ");
    scanf("%d", &search_id);

    for (int i = 0; i < employee_count; i++) {
        if (emp_list[i].id == search_id) {
            found = 1;
            printf("\n==================================================");
            printf("\n                 SALARY STATEMENT                 ");
            printf("\n==================================================");
            printf("\nEmp ID: %-15d Name: %s", emp_list[i].id, emp_list[i].name);
            printf("\nDesignation: %s", emp_list[i].designation);
            printf("\n--------------------------------------------------");
            printf("\nEARNINGS                         DEDUCTIONS       ");
            printf("\n--------------------------------------------------");
            printf("\nBasic Pay:    $%10.2f       Provident Fund: $%8.2f", emp_list[i].basic_salary, emp_list[i].pf);
            printf("\nHRA (20%%):    $%10.2f", emp_list[i].hra);
            printf("\nDA (10%%):     $%10.2f", emp_list[i].da);
            printf("\n--------------------------------------------------");
            printf("\nGROSS PAY:    $%10.2f       TOTAL DED.:     $%8.2f", emp_list[i].gross_salary, emp_list[i].pf);
            printf("\n==================================================");
            printf("\nNET TAKE-HOME PAY: $%10.2f", emp_list[i].net_salary);
            printf("\n==================================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }
}
