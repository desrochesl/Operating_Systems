#include <stddef.h>  // For NULL
#include <stdlib.h>

/**
 * allocates an array containing all even integers in the range [begin, end].
 *
 * @param begin starting integer of the range.
 * @param end ending integer of the range.
 * @return pointer to the newly allocated array of even integers. or NULL
 */
int* array_create_evens(int begin, int end) {
    int first = (begin % 2 != 0) ? begin + 1 : begin;
    int last = (end % 2 != 0) ? end - 1 : end;
    if (first > last) return NULL;
    int size = (last - first) / 2 + 1;
    int* arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) arr[i] = first + i * 2;
    return arr;
}