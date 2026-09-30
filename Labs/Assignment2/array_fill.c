#include <stddef.h>  // For NULL

/**
 * Fills an array with consecutive integers from begin to end up to array_len
 * elements.
 *
 * @param array pointer to the array to populate
 * @param array_len maximum # of elements the array can hold
 * @param begin starting integer value
 * @param end ending integer value
 * @return number of elements written to the array
 */
int array_fill(int* array, int array_len, int begin, int end) {
    if (!array || array_len <= 0 || begin > end) return 0;

    int count = 0;
    while (count < array_len && begin <= end) array[count++] = begin++;
    return count;
}
