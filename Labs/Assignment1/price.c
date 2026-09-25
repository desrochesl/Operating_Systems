#include <stdio.h>
/**
 * Calculates the total price of an order.
 * @param peritem price of each item
 * @param count numbers of items bought
 * @param bulk_limit minimum amount of items before discount
 */
int price(int peritem, int count, int bulk_limit) {
    if (count < 0 || peritem < 0) {
        return 0;
    }
    if (count < bulk_limit) {
        return count * peritem;
    }

    int halfPrice = (peritem / 2) * (bulk_limit % count);
    return (peritem / 2 * (count - bulk_limit) + (peritem * bulk_limit));
}
