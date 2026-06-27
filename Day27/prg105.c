#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"

typedef struct {
    int rollNumber;
    char name[50];
    float gpa;
} Student;

void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting system. Goodbye!\n"); exit(0);
            default: printf("Invalid option! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}

void addStudent() {
    FILE *fp = fopen(FILE_NAME, "a"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNumber);
    getchar(); 

    printf("Enter Full Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; 
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    fprintf(fp, "%d,%s,%.2f\n", s.rollNumber, s.name, s.gpa);
    fclose(fp);

    printf("Record added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found! Add a student first.\n");
        return;
    }

    Student s;
    printf("\n%-10s %-30s %-5s\n", "Roll No", "Name", "GPA");
    printf("--------------------------------------------------\n");

    while (fscanf(fp, "%d,%[^,],%f\n", &s.rollNumber, s.name, &s.gpa) != EOF) {
        printf("%-10d %-30s %-5.2f\n", s.rollNumber, s.name, s.gpa);
    }
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int roll, found = 0;
    Student s;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d,%[^,],%f\n", &s.rollNumber, s.name, &s.gpa) != EOF) {
        if (s.rollNumber == roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", s.rollNumber);
            printf("Name:        %s\n", s.name);
            printf("GPA:         %.2f\n", s.gpa);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}

void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempfp = fopen("temp.txt", "w");
    if (tempfp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int roll, found = 0;
    Student s;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d,%[^,],%f\n", &s.rollNumber, s.name, &s.gpa) != EOF) {
        if (s.rollNumber == roll) {
            found = 1; 
        } else {
            fprintf(tempfp, "%d,%s,%.2f\n", s.rollNumber, s.name, s.gpa);
        }
    }

    fclose(fp);
    fclose(tempfp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Record deleted successfully!\n");
    } else {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}
