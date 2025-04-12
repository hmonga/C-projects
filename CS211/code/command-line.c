#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if exactly one argument (besides the program name) is provided
    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return EXIT_FAILURE;  // Exit with an error code
    }

    // Access the name argument
    char *name = argv[1];

    // Print a greeting message
    printf("Hello, %s! Welcome to the program.\n", name);

    return EXIT_SUCCESS;
}
