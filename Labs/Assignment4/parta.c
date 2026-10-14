#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Include more header files (read the manpages to find out more!)

/**
 * Convert all letters in a string to uppercase. 
 * @param str a character array containing the string we are trying to convert to uppercase. 
 */
void to_uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

/**
 * Given a list of strings, convert all letters to uppercase characters and print them out. 
 * @param argc length of inputs
 * @param argv character array of inputs
 * @return 0 if success, 1 if failure
 */
int main(int argc, const char* argv[]) {
    if (argc < 2) {
        printf("ERROR: No arguments");
        return 1;
    }

    int count = argc - 1;
    char** upper = malloc(sizeof(char*) * count);
    if (!upper) return 1;

    for (int i = 1; i < argc; i++) {
        upper[i - 1] = strdup(argv[i]);
        if (!upper[i - 1]) return 1;
        to_uppercase(upper[i - 1]);
    }
    printf("%s", upper[0]);

    for (int i = 1; i < count; i++) {
        printf(",%s", upper[i]);
        free(upper[i]);
    }
    printf("\n");
    free(upper);
    return 0;
}