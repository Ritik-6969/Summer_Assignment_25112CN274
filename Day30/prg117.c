#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_SIZE 50

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int main(void) {
    char names[MAX_STUDENTS][NAME_SIZE];
    int rolls[MAX_STUDENTS];
    float marks[MAX_STUDENTS];
    int count = 0;
    int choice;

    printf("===== Student Record System =====\n");

    while (1) {
        printf("\n1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by roll number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        if (choice == 1) {
            if (count >= MAX_STUDENTS) {
                printf("Student list is full.\n");
                continue;
            }

            printf("\nEnter student name: ");
            fgets(names[count], NAME_SIZE, stdin);
            names[count][strcspn(names[count], "\n")] = '\0';

            printf("Enter roll number: ");
            scanf("%d", &rolls[count]);
            clearInputBuffer();

            printf("Enter marks: ");
            scanf("%f", &marks[count]);
            clearInputBuffer();

            count++;
            printf("Student added successfully!\n");
        } else if (choice == 2) {
            if (count == 0) {
                printf("No student records found.\n");
            } else {
                printf("\nStudent Records:\n");
                for (int i = 0; i < count; i++) {
                    printf("%d. Name: %s | Roll: %d | Marks: %.2f\n",
                           i + 1, names[i], rolls[i], marks[i]);
                }
            }
        } else if (choice == 3) {
            int searchRoll;
            int found = 0;

            printf("Enter roll number to search: ");
            scanf("%d", &searchRoll);
            clearInputBuffer();

            for (int i = 0; i < count; i++) {
                if (rolls[i] == searchRoll) {
                    printf("\nStudent found!\n");
                    printf("Name: %s\n", names[i]);
                    printf("Roll: %d\n", rolls[i]);
                    printf("Marks: %.2f\n", marks[i]);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Student not found.\n");
            }
        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
