#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SEAT_COUNT 10
#define NAME_LEN 50

void clear_input(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void display_seats(int booked[], char names[][NAME_LEN]) {
	printf("\nSeat map (1-%d):\n", SEAT_COUNT);
	for (int i = 0; i < SEAT_COUNT; ++i) {
		if (booked[i])
			printf("[%2d: X (%s)] ", i+1, names[i]);
		else
			printf("[%2d: -] ", i+1);
		if ((i+1) % 5 == 0) printf("\n");
	}
	printf("\n");
}

void book_ticket(int booked[], char names[][NAME_LEN]) {
	int seat;
	char temp[NAME_LEN];
	printf("Enter seat number (1-%d): ", SEAT_COUNT);
	if (scanf("%d", &seat) != 1) {
		printf("Invalid input.\n");
		clear_input();
		return;
	}
	if (seat < 1 || seat > SEAT_COUNT) {
		printf("Seat number out of range.\n");
		return;
	}
	if (booked[seat-1]) {
		printf("Seat %d is already booked by %s.\n", seat, names[seat-1]);
		return;
	}
	clear_input();
	printf("Enter customer name: ");
	if (!fgets(temp, sizeof(temp), stdin)) return;
	temp[strcspn(temp, "\n")] = '\0';
	strncpy(names[seat-1], temp, NAME_LEN-1);
	names[seat-1][NAME_LEN-1] = '\0';
	booked[seat-1] = 1;
	printf("Seat %d successfully booked for %s.\n", seat, names[seat-1]);
}

void cancel_booking(int booked[], char names[][NAME_LEN]) {
	int seat;
	printf("Enter seat number to cancel (1-%d): ", SEAT_COUNT);
	if (scanf("%d", &seat) != 1) {
		printf("Invalid input.\n");
		clear_input();
		return;
	}
	if (seat < 1 || seat > SEAT_COUNT) {
		printf("Seat number out of range.\n");
		return;
	}
	if (!booked[seat-1]) {
		printf("Seat %d is not currently booked.\n", seat);
		return;
	}
	booked[seat-1] = 0;
	names[seat-1][0] = '\0';
	printf("Booking for seat %d has been cancelled.\n", seat);
}

void view_bookings(int booked[], char names[][NAME_LEN]) {
	int any = 0;
	printf("\nCurrent bookings:\n");
	for (int i = 0; i < SEAT_COUNT; ++i) {
		if (booked[i]) {
			printf("Seat %2d - %s\n", i+1, names[i]);
			any = 1;
		}
	}
	if (!any) printf("No bookings yet.\n");
}

int main(void) {
	int booked[SEAT_COUNT] = {0};
	char names[SEAT_COUNT][NAME_LEN];
	for (int i = 0; i < SEAT_COUNT; ++i) names[i][0] = '\0';

	int choice;
	while (1) {
		printf("\nTicket Booking System\n");
		printf("1. Display seats\n");
		printf("2. Book ticket\n");
		printf("3. Cancel booking\n");
		printf("4. View bookings\n");
		printf("5. Exit\n");
		printf("Choose an option: ");
		if (scanf("%d", &choice) != 1) {
			printf("Invalid input. Try again.\n");
			clear_input();
			continue;
		}
		switch (choice) {
			case 1: display_seats(booked, names); break;
			case 2: book_ticket(booked, names); break;
			case 3: cancel_booking(booked, names); break;
			case 4: view_bookings(booked, names); break;
			case 5: printf("Exiting. Goodbye.\n"); return 0;
			default: printf("Invalid option.\n"); break;
		}
	}
	return 0;
}

