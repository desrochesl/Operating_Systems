#include <ctype.h>
#include <stdbool.h>  // For true/false
#include <stddef.h>   // For NULL

/**
 * Checks whether a given password string is valid
 *
 * @param s the password to validate
 * @return the validity of the password
 */
bool valid_password(const char* s) {
    if (!s) return false;
    int len = 0;
    while (s[len] != '\0') len++;
    if (len < 6 || len > 10) return false;

    int lower = 0, upper = 0;

    for (int i = 0; i < len - 1; i++) {
        if (isupper(s[i])) upper++;
        if (islower(s[i])) lower++;
    }
    if (lower < 2 || upper < 2) return false;
    return true;
}
