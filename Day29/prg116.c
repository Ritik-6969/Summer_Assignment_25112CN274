#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_ITEMS];
int item_count = 0;

void add_item();
void view_inventory();
void update_item();
void delete_item();
int find_index_by_id(int id);

int main() {
    int choice;

    do {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Item\n");
        printf("2. View All Items\n");
        printf("3. Update Item Stock\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your selection (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid data entry. Clearing buffer.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: add_item(); break;
            case 2: view_inventory(); break;
            case 3: update_item(); break;
            case 4: delete_item(); break;
            case 5: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Error: Invalid option. Choose 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Error: Inventory storage limit reached.\n");
        return;
    }

    Product p;
    printf("\nEnter Unique Product ID (Integer): ");
    scanf("%d", &p.id);

    if (find_index_by_id(p.id) != -1) {
        printf("Error: A product with ID %d already exists.\n", p.id);
        return;
    }

    printf("Enter Product Name: ");
    while (getchar() != '\n'); 
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0'; 

    printf("Enter Stock Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Price per Unit: ");
    scanf("%f", &p.price);

    inventory[item_count] = p;
    item_count++;
    printf("Success: Product added successfully!\n");
}

void view_inventory() {
    if (item_count == 0) {
        printf("\nInventory database is empty.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < item_count; i++) {
        printf("%-10d %-25s %-10d $%-9.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_item() {
    int id, index;
    printf("\nEnter the Product ID to update: ");
    scanf("%d", &id);

    index = find_index_by_id(id);
    if (index == -1) {
        printf("Error: Product with ID %d not found.\n", id);
        return;
    }

    printf("Current Quantity for %s: %d\n", inventory[index].name, inventory[index].quantity);
    printf("Enter New Stock Quantity: ");
    scanf("%d", &inventory[index].quantity);
    printf("Success: Stock quantity updated successfully!\n");
}

void delete_item() {
    int id, index;
    printf("\nEnter the Product ID to delete: ");
    scanf("%d", &id);

    index = find_index_by_id(id);
    if (index == -1) {
        printf("Error: Product with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < item_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    item_count--;
    printf("Success: Product deleted successfully!\n");
}

int find_index_by_id(int id) {
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            return i; 
        }
    }
    return -1; 
}
