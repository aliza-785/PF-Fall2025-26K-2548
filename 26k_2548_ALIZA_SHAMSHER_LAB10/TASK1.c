#include <stdio.h>

struct Flight {
    char flightNum[20];
    char depCity[50];
    char destCity[50];
    char date[20];
    int seats;
};

struct Flight bookSeat(struct Flight f) {
    if (f.seats > 0) {
        f.seats = f.seats - 1;
        printf("\nSeat booked successfully!\n");
    } else {
        printf("\nSorry, no seats available on this flight.\n");
    }
    return f;
}

void displayFlight(struct Flight f) {
    printf("\n------Flight Details -----\n");
    printf("Flight Number: %s\n", f.flightNum);
    printf("Departure City: %s\n", f.depCity);
    printf("Destination City: %s\n", f.destCity);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.seats);
}

int main() {
    struct Flight f1;
    int choice;

    printf("Enter Flight Number: ");
    scanf("%s", f1.flightNum);

    printf("Enter Departure City: ");
    scanf("%s", f1.depCity);

    printf("Enter Destination City: ");
    scanf("%s", f1.destCity);

    printf("Enter Date : ");
    scanf("%s", f1.date);

    printf("Enter Available Seats: ");
    scanf("%d", &f1.seats);

    do {
        printf("\n1. Book a Seat\n");
        printf("2. Display Flight Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            f1 = bookSeat(f1);
        } 
        else if (choice == 2) {
            displayFlight(f1);
        } 
        else if (choice == 3) {
            printf("Exiting program...\n");
        } 
        else {
            printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
