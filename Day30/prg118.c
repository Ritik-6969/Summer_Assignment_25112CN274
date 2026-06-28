#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int id;
	char title[100];
	char author[60];
	int copies;
} Book;

void clear_stdin(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void strip_newline(char *s) {
	size_t n = strlen(s);
	if (n && s[n-1] == '\n') s[n-1] = '\0';
}

void to_lower_inplace(char *s) {
	for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}

void addBook() {
	Book b;
	FILE *fp = fopen("library.dat", "ab");
	if (!fp) {
		perror("Unable to open data file");
		return;
	}

	printf("Enter book id: ");
	if (scanf("%d", &b.id) != 1) { clear_stdin(); printf("Invalid id\n"); fclose(fp); return; }
	clear_stdin();
	printf("Enter title: ");
	if (!fgets(b.title, sizeof b.title, stdin)) { fclose(fp); return; }
	strip_newline(b.title);
	printf("Enter author: ");
	if (!fgets(b.author, sizeof b.author, stdin)) { fclose(fp); return; }
	strip_newline(b.author);
	printf("Enter number of copies: ");
	if (scanf("%d", &b.copies) != 1) { clear_stdin(); printf("Invalid number\n"); fclose(fp); return; }
	clear_stdin();

	fwrite(&b, sizeof b, 1, fp);
	fclose(fp);
	printf("Book added.\n");
}

void displayBooks() {
	FILE *fp = fopen("library.dat", "rb");
	if (!fp) { printf("No records found.\n"); return; }
	Book b; int found = 0;
	printf("\n%-6s %-30s %-20s %-6s\n", "ID", "Title", "Author", "Copies");
	printf("---------------------------------------------------------------\n");
	while (fread(&b, sizeof b, 1, fp) == 1) {
		if (b.id == -1) continue; /* deleted */
		printf("%-6d %-30s %-20s %-6d\n", b.id, b.title, b.author, b.copies);
		found = 1;
	}
	if (!found) printf("No books to display.\n");
	fclose(fp);
}

void searchById() {
	int id; printf("Enter id to search: ");
	if (scanf("%d", &id) != 1) { clear_stdin(); printf("Invalid input\n"); return; }
	clear_stdin();
	FILE *fp = fopen("library.dat", "rb");
	if (!fp) { printf("No records found.\n"); return; }
	Book b; int found = 0;
	while (fread(&b, sizeof b, 1, fp) == 1) {
		if (b.id == id) {
			if (b.id == -1) break;
			printf("Found:\nID: %d\nTitle: %s\nAuthor: %s\nCopies: %d\n", b.id, b.title, b.author, b.copies);
			found = 1; break;
		}
	}
	if (!found) printf("Book not found.\n");
	fclose(fp);
}

void searchByTitle() {
	char q[100];
	printf("Enter title keyword: ");
	clear_stdin();
	if (!fgets(q, sizeof q, stdin)) return;
	strip_newline(q);
	char qlow[100]; strncpy(qlow, q, sizeof qlow); qlow[sizeof qlow-1] = '\0';
	to_lower_inplace(qlow);

	FILE *fp = fopen("library.dat", "rb");
	if (!fp) { printf("No records found.\n"); return; }
	Book b; int found = 0;
	while (fread(&b, sizeof b, 1, fp) == 1) {
		if (b.id == -1) continue;
		char lowtitle[100]; strncpy(lowtitle, b.title, sizeof lowtitle); lowtitle[sizeof lowtitle-1] = '\0';
		to_lower_inplace(lowtitle);
		if (strstr(lowtitle, qlow) != NULL) {
			printf("ID: %d | Title: %s | Author: %s | Copies: %d\n", b.id, b.title, b.author, b.copies);
			found = 1;
		}
	}
	if (!found) printf("No matching titles found.\n");
	fclose(fp);
}

void updateCopies(int id, int delta) {
	FILE *fp = fopen("library.dat", "r+b");
	if (!fp) { printf("No records found.\n"); return; }
	Book b; int found = 0;
	while (fread(&b, sizeof b, 1, fp) == 1) {
		if (b.id == id) {
			if (b.id == -1) break;
			int newCopies = b.copies + delta;
			if (newCopies < 0) { printf("Not enough copies to issue.\n"); fclose(fp); return; }
			b.copies = newCopies;
			fseek(fp, -((long)sizeof b), SEEK_CUR);
			fwrite(&b, sizeof b, 1, fp);
			fflush(fp);
			printf("Updated copies: %d\n", b.copies);
			found = 1; break;
		}
	}
	if (!found) printf("Book not found.\n");
	fclose(fp);
}

void issueBook() {
	int id; printf("Enter book id to issue: ");
	if (scanf("%d", &id) != 1) { clear_stdin(); printf("Invalid input\n"); return; }
	clear_stdin();
	updateCopies(id, -1);
}

void returnBook() {
	int id; printf("Enter book id to return: ");
	if (scanf("%d", &id) != 1) { clear_stdin(); printf("Invalid input\n"); return; }
	clear_stdin();
	updateCopies(id, +1);
}

void deleteBook() {
	int id; printf("Enter book id to delete: ");
	if (scanf("%d", &id) != 1) { clear_stdin(); printf("Invalid input\n"); return; }
	clear_stdin();
	FILE *fp = fopen("library.dat", "r+b");
	if (!fp) { printf("No records found.\n"); return; }
	Book b; int found = 0;
	while (fread(&b, sizeof b, 1, fp) == 1) {
		if (b.id == id) {
			b.id = -1; /* mark deleted */
			fseek(fp, -((long)sizeof b), SEEK_CUR);
			fwrite(&b, sizeof b, 1, fp);
			fflush(fp);
			printf("Book deleted.\n");
			found = 1; break;
		}
	}
	if (!found) printf("Book not found.\n");
	fclose(fp);
}

int main(void) {
	int choice;
	for (;;) {
		printf("\nLibrary Management System\n");
		printf("1. Add Book\n2. Display All Books\n3. Search by ID\n4. Search by Title\n5. Issue Book\n6. Return Book\n7. Delete Book\n8. Exit\n");
		printf("Enter choice: ");
		if (scanf("%d", &choice) != 1) { clear_stdin(); printf("Invalid choice\n"); continue; }
		clear_stdin();
		switch (choice) {
			case 1: addBook(); break;
			case 2: displayBooks(); break;
			case 3: searchById(); break;
			case 4: searchByTitle(); break;
			case 5: issueBook(); break;
			case 6: returnBook(); break;
			case 7: deleteBook(); break;
			case 8: printf("Goodbye.\n"); exit(0);
			default: printf("Invalid option\n");
		}
	}
	return 0;
}

