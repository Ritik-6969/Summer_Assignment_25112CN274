
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define NAME_LEN 50
#define DATA_FILE "accounts.dat"

typedef struct {
    int id;
    char name[NAME_LEN];
    double balance;
    int active;
} Account;

static Account accounts[MAX_ACCOUNTS];
static int next_id = 1;

void load_accounts(void) {
    FILE *f = fopen(DATA_FILE, "rb");
    if (!f) return;
    if (fread(&next_id, sizeof(next_id), 1, f) != 1) { fclose(f); return; }
    if (fread(accounts, sizeof(Account), MAX_ACCOUNTS, f) < 1) {
        /* no accounts saved */
    }
    fclose(f);
}

void save_accounts(void) {
    FILE *f = fopen(DATA_FILE, "wb");
    if (!f) {
        perror("Failed to save accounts");
        return;
    }
    fwrite(&next_id, sizeof(next_id), 1, f);
    fwrite(accounts, sizeof(Account), MAX_ACCOUNTS, f);
    fclose(f);
}

Account *find_account_by_id(int id) {
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (accounts[i].active && accounts[i].id == id) return &accounts[i];
    }
    return NULL;
}

void create_account(void) {
    int idx = -1;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) if (!accounts[i].active) { idx = i; break; }
    if (idx == -1) { puts("Account limit reached."); return; }

    char name[NAME_LEN];
    printf("Enter account holder name: ");
    if (!fgets(name, sizeof(name), stdin)) return;
    name[strcspn(name, "\n")] = '\0';

    double initial;
    printf("Enter initial deposit: ");
    if (scanf("%lf", &initial) != 1) { while (getchar()!='\n'); puts("Invalid amount"); return; }
    while (getchar()!='\n');

    accounts[idx].id = next_id++;
    strncpy(accounts[idx].name, name, NAME_LEN-1);
    accounts[idx].name[NAME_LEN-1] = '\0';
    accounts[idx].balance = initial;
    accounts[idx].active = 1;

    printf("Account created. ID: %d\n", accounts[idx].id);
}

void deposit(void) {
    int id; double amount;
    printf("Enter account ID: ");
    if (scanf("%d", &id) != 1) { while (getchar()!='\n'); puts("Invalid ID"); return; }
    Account *a = find_account_by_id(id);
    if (!a) { puts("Account not found."); while (getchar()!='\n'); return; }
    printf("Enter amount to deposit: ");
    if (scanf("%lf", &amount) != 1) { while (getchar()!='\n'); puts("Invalid amount"); return; }
    if (amount <= 0) { puts("Amount must be positive."); while (getchar()!='\n'); return; }
    a->balance += amount;
    printf("Deposit successful. New balance: %.2f\n", a->balance);
    while (getchar()!='\n');
}

void withdraw(void) {
    int id; double amount;
    printf("Enter account ID: ");
    if (scanf("%d", &id) != 1) { while (getchar()!='\n'); puts("Invalid ID"); return; }
    Account *a = find_account_by_id(id);
    if (!a) { puts("Account not found."); while (getchar()!='\n'); return; }
    printf("Enter amount to withdraw: ");
    if (scanf("%lf", &amount) != 1) { while (getchar()!='\n'); puts("Invalid amount"); return; }
    if (amount <= 0) { puts("Amount must be positive."); while (getchar()!='\n'); return; }
    if (amount > a->balance) { puts("Insufficient funds."); while (getchar()!='\n'); return; }
    a->balance -= amount;
    printf("Withdrawal successful. New balance: %.2f\n", a->balance);
    while (getchar()!='\n');
}

void display_account(void) {
    int id;
    printf("Enter account ID: ");
    if (scanf("%d", &id) != 1) { while (getchar()!='\n'); puts("Invalid ID"); return; }
    Account *a = find_account_by_id(id);
    if (!a) { puts("Account not found."); while (getchar()!='\n'); return; }
    printf("Account ID: %d\nName: %s\nBalance: %.2f\n", a->id, a->name, a->balance);
    while (getchar()!='\n');
}

void list_accounts(void) {
    printf("%-6s %-20s %10s\n", "ID", "Name", "Balance");
    printf("------------------------------------------------\n");
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (accounts[i].active) printf("%-6d %-20s %10.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
}

int main(void) {
    load_accounts();
    for (;;) {
        printf("\nBank System Menu:\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display account\n");
        printf("5. List accounts\n");
        printf("6. Save and exit\n");
        printf("Choose option: ");
        int choice;
        if (scanf("%d", &choice) != 1) { while (getchar()!='\n'); puts("Invalid choice"); continue; }
        while (getchar()!='\n');
        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: display_account(); break;
            case 5: list_accounts(); break;
            case 6: save_accounts(); puts("Saved. Exiting."); return 0;
            default: puts("Invalid option"); break;
        }
    }
    return 0;
}
