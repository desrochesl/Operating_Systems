#include <ctype.h>
#include <stddef.h>  // For NULL

/**
 * Fills a destination character buffer up to capacity dest_cap - 1 with a
 * repeated character c
 * @param dest[] stores the repeated characters
 * @param dest_cap the amount of characters to repeat - 1
 * @param c the character chosen to repeat
 */
void string_fill(char dest[], int dest_cap, char c) {
    if (!dest || dest_cap <= 0) return;
    int i = 0;

    while (i < dest_cap - 1) dest[i++] = c;

    dest[i] = '\0';
}
