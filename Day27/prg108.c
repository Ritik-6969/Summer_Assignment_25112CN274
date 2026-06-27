#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    char class_name[10];
    int marks[5];
    int total;
    float percentage;
    char grade[5];
    char result[10];
};

void calculate_results(struct Student *s) {
    s->total = 0;
    int failed_subjects = 0;

    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
        if (s->marks[i] < 40) {
            failed_subjects++;
        }
    }

    s->percentage = s->total / 5.0;

    if (failed_subjects > 0) {
        strcpy(s->result, "FAIL");
        strcpy(s->grade, "F");
    } else {
        strcpy(s->result, "PASS");
        if (s->percentage >= 90) strcpy(s->grade, "A+");
        else if (s->percentage >= 80) strcpy(s->grade, "A");
        else if (s->percentage >= 70) strcpy(s->grade, "B");
        else if (s->percentage >= 60) strcpy(s->grade, "C");
        else if (s->percentage >= 50) strcpy(s->grade, "D");
        else strcpy(s->grade, "E");
    }
}

int main() {
    struct Student s;
    const char *subjects[5] = {"Mathematics", "Physics", "Chemistry", "English", "Computer Sci"};

    printf("==================================================\n");
    printf("        MARKSHEET GENERATION SYSTEM               \n");
    printf("==================================================\n");

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; 
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll_no);
    
    printf("Enter Class/Standard: ");
    scanf("%s", s.class_name);

    printf("\nEnter marks out of 100 for each subject:\n");
    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("%s: ", subjects[i]);
            scanf("%d", &s.marks[i]);
            
            if (s.marks[i] >= 0 && s.marks[i] <= 100) {
                break;
            }
            printf("Invalid Input! Marks must be between 0 and 100.\n");
        }
    }

    calculate_results(&s);

    printf("\n==================================================\n");
    printf("              OFFICIAL REPORT CARD                \n");
    printf("==================================================\n");
    printf(" Name: %-25s Roll No: %-10d\n", s.name, s.roll_no);
    printf(" Class: %-24s Status: %-10s\n", s.class_name, s.result);
    printf("--------------------------------------------------\n");
    printf(" %-20s | %-10s | %-10s\n", "SUBJECT", "MAX MARKS", "OBTAINED");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        printf(" %-20s | %-10d | %-10d\n", subjects[i], 100, s.marks[i]);
    }
    
    printf("--------------------------------------------------\n");
    printf(" Grand Total:  %d / 500\n", s.total);
    printf(" Percentage:   %.2f%%\n", s.percentage);
    printf(" Final Grade:  %s\n", s.grade);
    printf("==================================================\n");

    return 0;
}
