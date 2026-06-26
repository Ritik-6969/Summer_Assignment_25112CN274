#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 4

typedef struct {
    char question_text[150];
    char options[4][50];
    char correct_option;
} QuizQuestion;

void display_welcome_message();
void run_quiz(QuizQuestion quiz[]);
void display_final_score(int score, int total);

int main() {
    QuizQuestion quiz[TOTAL_QUESTIONS] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Python", "B. C", "C. Java", "D. Assembly"},
            'B'
        },
        {
            "What is the format specifier used to print an integer in C?",
            {"A. %f", "B. %c", "C. %d", "D. %s"},
            'C'
        },
        {
            "Which of the following is NOT a valid loop in C?",
            {"A. while", "B. do-while", "C. for", "D. foreach"},
            'D'
        },
        {
            "What does the 'S' in CPU stand for?",
            {"A. System", "B. Central", "C. Processing", "D. None of the above"},
            'D' 
        }
    };

    display_welcome_message();
    run_quiz(quiz);

    return 0;
}

void display_welcome_message() {
    printf("==========================================\n");
    printf("        WELCOME TO THE TECH QUIZ          \n");
    printf("==========================================\n");
    printf("Instructions: Enter A, B, C, or D for each.\n");
    printf("Press [ENTER] to start the quiz...");
    getchar(); 
    printf("\n");
}

void run_quiz(QuizQuestion quiz[]) {
    int score = 0;
    char user_guess;

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("------------------------------------------\n");
        printf("Question %d: %s\n\n", i + 1, quiz[i].question_text);
        
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }
        
        printf("\nYour Answer (A/B/C/D): ");
        scanf(" %c", &user_guess); 

        user_guess = toupper(user_guess);

        if (user_guess == quiz[i].correct_option) {
            printf("\n✅ CORRECT!\n");
            score++;
        } else {
            printf("\n❌ WRONG! The correct answer was %c.\n", quiz[i].correct_option);
        }
    }

    display_final_score(score, TOTAL_QUESTIONS);
}

void display_final_score(int score, int total) {
    float percentage = ((float)score / total) * 100;

    printf("\n==========================================\n");
    printf("               QUIZ OVER                  \n");
    printf("==========================================\n");
    printf("Your Final Score: %d out of %d\n", score, total);
    printf("Percentage: %.2f%%\n", percentage);
    
    if (percentage >= 75.0) {
        printf("Performance: Excellent Job! 🎉\n");
    } else if (percentage >= 50.0) {
        printf("Performance: Good Try! 👍\n");
    } else {
        printf("Performance: Better Luck Next Time! 📚\n");
    }
    printf("==========================================\n");
}
