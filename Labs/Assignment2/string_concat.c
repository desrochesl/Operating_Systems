#include <ctype.h>
#include <stddef.h>  // For NULL

/**
 * Appends the contents of src2 to src1
 *
 * @param src1 destination string to be modified
 * @param src1_cap total capacity of scr1
 * @param src2 source string to append to src1
 */
void string_concat(char* src1, int src1_cap, const char* src2) {
    if (!src1 || !src2 || src1_cap <= 0) return;
    int len = 0;
    while (src1[len] != '\0') len++;

    int i = 0;
    while (len < src1_cap - 1 && src2[i] != '\0') {
        src1[len++] = src2[i];
        i++;
    }
    src1[len] = '\0';
}
