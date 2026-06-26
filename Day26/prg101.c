#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, attempts = 0;

    srand(time(0));

    secret_number = (rand() % 100) + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a secret number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    do {
        printf("Enter your guess: ");
        
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        attempts++;

        if (guess > secret_number) {
            printf("Too High! Try a smaller number.\n\n");
        } 
        else if (guess < secret_number) {
            printf("Too Low! Try a larger number.\n\n");
        } 
        else {
            printf("\nCongratulations! 🎉 You guessed the number in %d attempts.\n", attempts);
        }

    } while (guess != secret_number);

    return 0;
}
