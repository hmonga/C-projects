#include <stdio.h>
#include <stdlib.h>

int main() {
    int age = 25;          // Integer
    float height = 5.9f;   // Float
    double pi = 3.14159;   // Double
    char grade = 'A';      // Character
    char name[] = "Alice"; // String (char array)

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.1f\n", height);
    printf("Pi: %.5lf\n", pi);
    printf("Grade: %c\n", grade);

    return EXIT_SUCCESS;
}
