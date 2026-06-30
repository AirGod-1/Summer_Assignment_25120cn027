/*
 * LOGIC: The Struct Array Engine (Ticket Booking)
 * 1. Define a Ticket struct with Ticket ID, Passenger Name, Seat No, and Status.
 * 2. Maintain a fixed-size seat pool; mark seats booked/cancelled in place.
 * 3. Use an independent sequential ticket counter to guarantee unique IDs.
 * 4. Implement bulletproof buffer-flushing to protect against invalid menu and seat selections.
 */

#include <stdio.h>
#include <string.h>

#define MAX_SEATS 50

struct Ticket {
    int ticketId;
    char passengerName[50];
    int seatNo;
    int booked;
};

struct Ticket seats[MAX_SEATS];
int ticketCounter = 1;


void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void initSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNo = i + 1;
        seats[i].booked = 0;
        seats[i].ticketId = 0;
        strcpy(seats[i].passengerName, "");
    }
}

void bookTicket() {
    int seatNo;
    printf("Enter seat number (1-%d): ", MAX_SEATS);

    if (scanf("%d", &seatNo) != 1) {
        printf("Invalid numeric input.\n");
        flushBuffer();
        return;
    }

    if (seatNo < 1 || seatNo > MAX_SEATS) {
        printf("Error: Invalid seat number.\n");
        return;
    }

    int idx = seatNo - 1;
    if (seats[idx].booked) {
        printf("Error: Seat %d is already booked.\n", seatNo);
        return;
    }

    printf("Enter Passenger Name: ");
    flushBuffer();
    fgets(seats[idx].passengerName, sizeof(seats[idx].passengerName), stdin);
    seats[idx].passengerName[strcspn(seats[idx].passengerName, "\n")] = '\0';

    seats[idx].booked = 1;
    seats[idx].ticketId = ticketCounter++;

    printf("Success! Ticket ID: %d assigned to Seat %d.\n", seats[idx].ticketId, seats[idx].seatNo);
}

void cancelTicket() {
    int ticketId;
    printf("Enter Ticket ID to cancel: ");
    if (scanf("%d", &ticketId) != 1) {
        printf("Invalid numeric input.\n");
        flushBuffer();
        return;
    }

    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].booked && seats[i].ticketId == ticketId) {
            seats[i].booked = 0;
            seats[i].ticketId = 0;
            strcpy(seats[i].passengerName, "");
            printf("Success: Ticket cancelled. Seat %d is now vacant.\n", seats[i].seatNo);
            return;
        }
    }
    printf("Error: Ticket ID not found.\n");
}

void displayTickets() {
    int activeBookings = 0;

    printf("\n%-10s %-10s %-25s %-10s\n", "Seat", "Ticket ID", "Passenger", "Status");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].booked) {
            printf("%-10d %-10d %-25s %-10s\n",
                   seats[i].seatNo,
                   seats[i].ticketId,
                   seats[i].passengerName,
                   "Booked");
            activeBookings++;
        }
    }

    if (activeBookings == 0) {
        printf("No active reservations found in the system.\n");
    }
}

void searchTicket() {
    int ticketId;
    printf("Enter Ticket ID to search: ");
    if (scanf("%d", &ticketId) != 1) {
        printf("Invalid numeric input.\n");
        flushBuffer();
        return;
    }

    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].booked && seats[i].ticketId == ticketId) {
            printf("\nTicket Verification Found:\n");
            printf(" -> Seat Position: %d\n -> Passenger Name: %s\n", seats[i].seatNo, seats[i].passengerName);
            return;
        }
    }
    printf("Error: Ticket ID not found.\n");
}

int main() {
    initSeats();
    int choice;
    do {
        printf("\n=== Ticket Booking System ===\n");
        printf("1. Book Ticket\n2. Cancel Ticket\n3. Display Booked Tickets\n4. Search Ticket\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Please enter a menu digit.\n");
            flushBuffer();
            continue;
        }

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: displayTickets(); break;
            case 4: searchTicket(); break;
            case 0: printf("Exiting Booking System...\n"); break;
            default: printf("Invalid choice option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}