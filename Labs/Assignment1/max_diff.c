#include <stdlib.h>  // For NULL

/**
 * Calculates the difference between the smallest and largest integers in an
 * array
 * @param array list of numbers
 * @param alen length of array
 */
int max_diff(int* array, int alen) {
    if (alen < 1) return 0;
    int min = 1000000000;
    int max = -1000000000;
    int i;

    for (i = 0; i < alen; i++) {
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }
    return max - min;
}
