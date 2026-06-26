#include <stdio.h>
#include <stdbool.h>

void displayMenu();
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main() {
    const int DEFAULT_PIN = 1234;
    double accountBalance = 5000.00; 
    
    int enteredPin;
    int pinAttempts = 0;
    const int MAX_ATTEMPTS = 3;
    bool isAuthenticated = false;
    int choice;

    printf("=== Welcome to the ATM Simulation System ===\n");

    while (pinAttempts < MAX_ATTEMPTS) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input format. Please enter numbers only.\n\n");
            while (getchar() != '\n'); 
            pinAttempts++;
            continue;
        }

        if (enteredPin == DEFAULT_PIN) {
            isAuthenticated = true;
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", MAX_ATTEMPTS - pinAttempts);
        }
    }

    if (!isAuthenticated) {
        printf("Too many incorrect attempts. Your card has been locked.\n");
        printf("Please contact your bank branch manager for assistance.\n");
        return 0;
    }

    do {
        displayMenu();
        printf("Select an option (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection string. Try again.\n");
            while (getchar() != '\n');
            choice = 0; 
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(accountBalance);
                break;
            case 2:
                accountBalance = depositMoney(accountBalance);
                break;
            case 3:
                accountBalance = withdrawMoney(accountBalance);
                break;
            case 4:
                printf("\nThank you for using our ATM services. Goodbye!\n");
                break;
            default:
                printf("Invalid option selected. Please select a valid number (1-4).\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n---------- ATM MAIN MENU ----------\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Cash\n");
    printf("3. Withdraw Cash\n");
    printf("4. Exit ATM Session\n");
    printf("-----------------------------------\n");
}

void checkBalance(double balance) {
    printf("\n[BALANCE] Your available balance is: $%.2f\n", balance);
}

double depositMoney(double balance) {
    double depositAmount;
    printf("\nEnter the amount to deposit: $");
    scanf("%double", &depositAmount);

    if (depositAmount <= 0) {
        printf("[ERROR] Deposit amount must be greater than zero.\n");
    } else {
        balance += depositAmount;
        printf("[SUCCESS] $%.2f deposited successfully.\n", depositAmount);
        printf("[NEW BALANCE] $%.2f\n", balance);
    }
    return balance;
}

double withdrawMoney(double balance) {
    double withdrawAmount;
    printf("\nEnter the amount to withdraw: $");
    scanf("%double", &withdrawAmount);

    if (withdrawAmount <= 0) {
        printf("[ERROR] Withdrawal amount must be greater than zero.\n");
    } else if (withdrawAmount > balance) {
        printf("[ERROR] Insufficient funds! Current Balance: $%.2f\n", balance);
    } else {
        balance -= withdrawAmount;
        printf("[SUCCESS] Please collect your cash: $%.2f\n", withdrawAmount);
        printf("[NEW BALANCE] $%.2f\n", balance);
    }
    return balance;
}
