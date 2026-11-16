#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

int addMovie(struct Movie m[], int count) {
    printf("\nEnter Movie Title: ");
    scanf(" %[^\n]", m[count].title);

    printf("Enter Genre: ");
    scanf(" %[^\n]", m[count].genre);

    printf("Enter Director: ");
    scanf(" %[^\n]", m[count].director);

    printf("Enter Release Year: ");
    scanf("%d", &m[count].releaseYear);

    printf("Enter Rating (out of 10): ");
    scanf("%f", &m[count].rating);

    count = count + 1;
    printf("Movie added!\n");
    return count;
}

void searchByGenre(struct Movie m[], int count) {
    char searchGenre[30];
    int found = 0;
    int i;

    printf("\nEnter genre to search: ");
    scanf(" %[^\n]", searchGenre);

    printf("\n Search Results\n");
    for (i = 0; i < count; i++) {
        if (strcmp(m[i].genre, searchGenre) == 0) {
            printf("Title: %s\n", m[i].title);
            printf("Director: %s\n", m[i].director);
            printf("Year: %d\n", m[i].releaseYear);
            printf("Rating: %.1f/10\n\n", m[i].rating);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No movies found in this genre.\n");
    }
}

void displayAll(struct Movie m[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo movies in the list yet.\n");
        return;
    }

    printf("\n--- All Movies ---\n");
    for (i = 0; i < count; i++) {
        printf("Title: %s\n", m[i].title);
        printf("Genre: %s\n", m[i].genre);
        printf("Director: %s\n", m[i].director);
        printf("Release Year: %d\n", m[i].releaseYear);
        printf("Rating: %.1f/10\n", m[i].rating);
        printf("\n");
    }
}

int main() {
    struct Movie list[50];
    int totalMovies = 0;
    int choice;

    do {
        printf("\n1. Add New Movie\n");
        printf("2. Search Movie by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            totalMovies = addMovie(list, totalMovies);
        } 
        else if (choice == 2) {
            searchByGenre(list, totalMovies);
        } 
        else if (choice == 3) {
            displayAll(list, totalMovies);
        } 
        else if (choice == 4) {
            printf("Goodbye!\n");
        } 
        else {
            printf("Wrong input!! try again.\n");
        }

    } while (choice != 4);

    return 0;
}
