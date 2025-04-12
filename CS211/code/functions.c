#include <stdio.h>
#include <stdlib.h>

// Function prototype
int add(int a, int b);  // Declares the function signature

int main() {
    int num1 = 15, num2 = 25;

    // Call the function
    int result = add(num1, num2);

    printf("The sum of %d and %d is %d\n", num1, num2, result);

    return EXIT_SUCCESS;
}

// Function definition
int add(int a, int b) {
    return a + b;  // Returns the sum of two integers
}
