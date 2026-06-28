#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_EMAIL 50
#define MAX_ADDRESS 100
#define FILENAME "contacts.dat"

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
    char address[MAX_ADDRESS];
} Contact;

Contact contacts[MAX_CONTACTS];
int totalContacts = 0;

void displayMenu();
void addContact();
void displayAllContacts();
void searchContact();
void deleteContact();
void editContact();
void saveContactsToFile();
void loadContactsFromFile();

int main() {
    int choice;
    
    loadContactsFromFile();
    
    while (1) {
        displayMenu();
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);
        getchar(); 
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayAllContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                editContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                saveContactsToFile();
                printf("\n*** Contacts saved successfully! ***\n");
                break;
            case 7:
                printf("\nExiting... Contacts saved.\n");
                saveContactsToFile();
                exit(0);
            default:
                printf("\n*** Invalid choice! Please try again. ***\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n========== CONTACT MANAGEMENT SYSTEM ==========\n");
    printf("1. Add New Contact\n");
    printf("2. Display All Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Edit Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Save Contacts\n");
    printf("7. Exit\n");
    printf("==============================================\n");
}

void addContact() {
    if (totalContacts >= MAX_CONTACTS) {
        printf("\n*** Contact list is full! ***\n");
        return;
    }
    
    printf("\n--- Add New Contact ---\n");
    
    printf("Enter name: ");
    fgets(contacts[totalContacts].name, MAX_NAME, stdin);
    contacts[totalContacts].name[strcspn(contacts[totalContacts].name, "\n")] = '\0';
    
    if (strlen(contacts[totalContacts].name) == 0) {
        printf("*** Contact name cannot be empty! ***\n");
        return;
    }
    
    printf("Enter phone number: ");
    fgets(contacts[totalContacts].phone, MAX_PHONE, stdin);
    contacts[totalContacts].phone[strcspn(contacts[totalContacts].phone, "\n")] = '\0';
    
    printf("Enter email: ");
    fgets(contacts[totalContacts].email, MAX_EMAIL, stdin);
    contacts[totalContacts].email[strcspn(contacts[totalContacts].email, "\n")] = '\0';
    
    printf("Enter address: ");
    fgets(contacts[totalContacts].address, MAX_ADDRESS, stdin);
    contacts[totalContacts].address[strcspn(contacts[totalContacts].address, "\n")] = '\0';
    
    totalContacts++;
    printf("\n*** Contact added successfully! ***\n");
}

void displayAllContacts() {
    if (totalContacts == 0) {
        printf("\n*** No contacts available! ***\n");
        return;
    }
    
    printf("\n--- All Contacts ---\n");
    printf("===============================================\n");
    
    for (int i = 0; i < totalContacts; i++) {
        printf("\nContact #%d\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("Address: %s\n", contacts[i].address);
        printf("---------------------------------------\n");
    }
}

void searchContact() {
    if (totalContacts == 0) {
        printf("\n*** No contacts available! ***\n");
        return;
    }
    
    char searchName[MAX_NAME];
    printf("\n--- Search Contact ---\n");
    printf("Enter contact name to search: ");
    fgets(searchName, MAX_NAME, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    
    int found = 0;
    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("\n*** Contact Found! ***\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("Address: %s\n", contacts[i].address);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\n*** Contact not found! ***\n");
    }
}

void editContact() {
    if (totalContacts == 0) {
        printf("\n*** No contacts available! ***\n");
        return;
    }
    
    char searchName[MAX_NAME];
    printf("\n--- Edit Contact ---\n");
    printf("Enter contact name to edit: ");
    fgets(searchName, MAX_NAME, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    
    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("\n*** Contact found! ***\n");
            printf("Current information:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("Address: %s\n", contacts[i].address);
            
            printf("\nEnter new phone (or press Enter to skip): ");
            char temp[MAX_PHONE];
            fgets(temp, MAX_PHONE, stdin);
            if (temp[0] != '\n') {
                temp[strcspn(temp, "\n")] = '\0';
                strcpy(contacts[i].phone, temp);
            }
            
            printf("Enter new email (or press Enter to skip): ");
            fgets(temp, MAX_EMAIL, stdin);
            if (temp[0] != '\n') {
                temp[strcspn(temp, "\n")] = '\0';
                strcpy(contacts[i].email, temp);
            }
            
            printf("Enter new address (or press Enter to skip): ");
            fgets(temp, MAX_ADDRESS, stdin);
            if (temp[0] != '\n') {
                temp[strcspn(temp, "\n")] = '\0';
                strcpy(contacts[i].address, temp);
            }
            
            printf("\n*** Contact updated successfully! ***\n");
            return;
        }
    }
    
    printf("\n*** Contact not found! ***\n");
}

void deleteContact() {
    if (totalContacts == 0) {
        printf("\n*** No contacts available! ***\n");
        return;
    }
    
    char searchName[MAX_NAME];
    printf("\n--- Delete Contact ---\n");
    printf("Enter contact name to delete: ");
    fgets(searchName, MAX_NAME, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    
    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("\n*** Contact found! ***\n");
            printf("Deleting: %s\n", contacts[i].name);
            
            for (int j = i; j < totalContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            
            totalContacts--;
            printf("*** Contact deleted successfully! ***\n");
            return;
        }
    }
    
    printf("\n*** Contact not found! ***\n");
}

void saveContactsToFile() {
    FILE *file = fopen(FILENAME, "wb");
    
    if (file == NULL) {
        printf("*** Error opening file for writing! ***\n");
        return;
    }
    
    fwrite(&totalContacts, sizeof(int), 1, file);
    
    for (int i = 0; i < totalContacts; i++) {
        fwrite(&contacts[i], sizeof(Contact), 1, file);
    }
    
    fclose(file);
}

void loadContactsFromFile() {
    FILE *file = fopen(FILENAME, "rb");
    
    if (file == NULL) {
        totalContacts = 0;
        return;
    }
    
    fread(&totalContacts, sizeof(int), 1, file);
    
    for (int i = 0; i < totalContacts; i++) {
        fread(&contacts[i], sizeof(Contact), 1, file);
    }
    
    fclose(file);
}
