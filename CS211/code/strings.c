#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For string functions

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";

    // Concatenating strings
    strcat(str1, ", ");
    strcat(str1, str2);
    printf("Concatenated String: %s\n", str1);

    // Length of string
    printf("Length of str1: %lu\n", strlen(str1));

    // Copying a string
    char str3[20];
    strcpy(str3, str1);
    printf("Copied String: %s\n", str3);

    return EXIT_SUCCESS;
}
