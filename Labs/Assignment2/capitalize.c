#include <ctype.h>
#include <stddef.h>  // For NULL
#include <stdlib.h>
#include <string.h>

/**
 * Allocates a new string and returns an uppercase copy of the input string.
 *
 * @param s the inputted character array
 * @return an uppercate copy of s
 */
char* capitalize(const char* s) {
    if (s == NULL) return NULL;
    char* str = malloc(strlen(s) + 1);
    for (int i = 0; i <= strlen(s); i++) {
        str[i] = toupper(s[i]);
    }
    return str;
}
