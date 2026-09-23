/**
 * Calculates x to the power of y
 * @param x constant
 * @param y exponent
 */
int power(int x, int y) {
    if (y == 0) return 1;

    if (x < 0 || y < 0) return 0;
    int i;
    int pow = x;
    for (i = 1; i < y; i++) {
        pow *= x;
    }
    return pow;
}
