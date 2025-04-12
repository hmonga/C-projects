#include <stdio.h>
#include <stdlib.h>

int main() {
    char firstName[50];
    char lastName[50];
    int birthYear;
    char city[50];

    // Prompt the user for personal details
    printf("Enter your first name: ");
    scanf("%49s", firstName);  // Read the first name
    printf("Enter your last name: ");
    scanf("%49s", lastName);   // Read the last name
    printf("Enter your birth year: ");
    scanf("%d", &birthYear);   // Read the birth year
    printf("Enter the city you live in: ");
    scanf("%49s", city);       // Read the city name

    // Display the collected information
    printf("\nHello, %s %s!\n", firstName, lastName);
    printf("You were born in %d and live in %s.\n", birthYear, city);

    return EXIT_SUCCESS;
}
