#include <stdlib.h>  // For NULL

/**
 * Collects all positive numbers and add them together
 * @param array array of numbers
 * @param alen length of array
 */
int add_all_pos(int* array, int alen) {
    if (alen == 0) return 0;
    int i;
    int pos = 0;
    for (i = 0; i < alen; i++) {
        if (array[i] > 0) pos += array[i];
    }
    return pos;
}
