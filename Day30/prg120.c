#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 50
#define NAME_LEN 50
#define SUBJECTS 3

typedef struct {
    int id;
    char name[NAME_LEN];
    int marks[SUBJECTS];
    int total;
    float average;
    char grade;
} Student;

static Student students[MAX_STUDENTS];
static int student_count = 0;

void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void trim_newline(char *text) {
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}

void calculate_result(Student *s) {
    s->total = 0;
    for (int i = 0; i < SUBJECTS; ++i) {
        s->total += s->marks[i];
    }
    s->average = (float)s->total / SUBJECTS;

    if (s->average >= 90.0f) s->grade = 'A';
    else if (s->average >= 75.0f) s->grade = 'B';
    else if (s->average >= 60.0f) s->grade = 'C';
    else if (s->average >= 50.0f) s->grade = 'D';
    else s->grade = 'F';
}

int find_student_index_by_id(int id) {
    for (int i = 0; i < student_count; ++i) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void add_student(void) {
    if (student_count >= MAX_STUDENTS) {
        puts("Student list is full.");
        return;
    }

    Student s;
    printf("Enter student ID: ");
    if (scanf("%d", &s.id) != 1) {
        clear_stdin();
        puts("Invalid ID.");
        return;
    }
    clear_stdin();

    if (find_student_index_by_id(s.id) >= 0) {
        puts("A student with that ID already exists.");
        return;
    }

    printf("Enter student name: ");
    if (!fgets(s.name, sizeof s.name, stdin)) {
        return;
    }
    trim_newline(s.name);

    for (int i = 0; i < SUBJECTS; ++i) {
        printf("Enter marks for subject %d: ", i + 1);
        if (scanf("%d", &s.marks[i]) != 1) {
            clear_stdin();
            puts("Invalid mark.");
            return;
        }
        if (s.marks[i] < 0 || s.marks[i] > 100) {
            puts("Marks must be between 0 and 100.");
            return;
        }
    }
    clear_stdin();

    calculate_result(&s);
    students[student_count++] = s;
    puts("Student added successfully.");
}

void display_students(void) {
    if (student_count == 0) {
        puts("No students to display.");
        return;
    }

    printf("\n%-6s %-20s %-8s %-8s %-8s %-8s %-8s %-6s\n",
           "ID", "Name", "Sub1", "Sub2", "Sub3", "Total", "Average", "Grade");
    puts("----------------------------------------------------------------------------");

    for (int i = 0; i < student_count; ++i) {
        Student *s = &students[i];
        printf("%-6d %-20s %-8d %-8d %-8d %-8d %-8.2f %-6c\n",
               s->id, s->name,
               s->marks[0], s->marks[1], s->marks[2],
               s->total, s->average, s->grade);
    }
}

void search_student(void) {
    int id;
    printf("Enter student ID to search: ");
    if (scanf("%d", &id) != 1) {
        clear_stdin();
        puts("Invalid ID.");
        return;
    }
    clear_stdin();

    int idx = find_student_index_by_id(id);
    if (idx < 0) {
        puts("Student not found.");
        return;
    }

    Student *s = &students[idx];
    printf("Found student:\nID: %d\nName: %s\nMarks: %d, %d, %d\nTotal: %d\nAverage: %.2f\nGrade: %c\n",
           s->id, s->name, s->marks[0], s->marks[1], s->marks[2], s->total, s->average, s->grade);
}

void update_student(void) {
    int id;
    printf("Enter student ID to update: ");
    if (scanf("%d", &id) != 1) {
        clear_stdin();
        puts("Invalid ID.");
        return;
    }
    clear_stdin();

    int idx = find_student_index_by_id(id);
    if (idx < 0) {
        puts("Student not found.");
        return;
    }

    Student *s = &students[idx];
    char buffer[NAME_LEN];

    printf("Enter new name (leave blank to keep '%s'): ", s->name);
    if (!fgets(buffer, sizeof buffer, stdin)) {
        return;
    }
    trim_newline(buffer);
    if (buffer[0] != '\0') {
        strncpy(s->name, buffer, NAME_LEN - 1);
        s->name[NAME_LEN - 1] = '\0';
    }

    for (int i = 0; i < SUBJECTS; ++i) {
        printf("Enter new marks for subject %d (current %d): ", i + 1, s->marks[i]);
        if (scanf("%d", &s->marks[i]) != 1) {
            clear_stdin();
            puts("Invalid mark.");
            return;
        }
        if (s->marks[i] < 0 || s->marks[i] > 100) {
            puts("Marks must be between 0 and 100.");
            return;
        }
    }
    clear_stdin();

    calculate_result(s);
    puts("Student updated successfully.");
}

void delete_student(void) {
    int id;
    printf("Enter student ID to delete: ");
    if (scanf("%d", &id) != 1) {
        clear_stdin();
        puts("Invalid ID.");
        return;
    }
    clear_stdin();

    int idx = find_student_index_by_id(id);
    if (idx < 0) {
        puts("Student not found.");
        return;
    }

    for (int i = idx; i + 1 < student_count; ++i) {
        students[i] = students[i + 1];
    }
    student_count--;
    puts("Student record deleted.");
}

void show_menu(void) {
    puts("\nStudent Management Mini Project");
    puts("1. Add student");
    puts("2. Display all students");
    puts("3. Search student by ID");
    puts("4. Update student record");
    puts("5. Delete student record");
    puts("6. Exit");
    printf("Choose an option: ");
}

int main(void) {
    int option;
    while (1) {
        show_menu();
        if (scanf("%d", &option) != 1) {
            clear_stdin();
            puts("Invalid option. Please enter a number.");
            continue;
        }
        clear_stdin();

        switch (option) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6: puts("Exiting application."); return 0;
            default: puts("Please choose a valid option.");
        }
    }
    return 0;
}
