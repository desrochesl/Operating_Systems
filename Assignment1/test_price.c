#include "unity.h"  // For Unity Unit Tests

// Function declaration so that we can use them here
int price(int peritem, int count, int bulk_limit);

void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}
void test_price(void) {
    TEST_ASSERT_EQUAL_INT(2, price(2, 1, 10));
    TEST_ASSERT_EQUAL_INT(6, price(2, 3, 10));
    TEST_ASSERT_EQUAL_INT(18, price(2, 9, 10));
    TEST_ASSERT_EQUAL_INT(20, price(2, 10, 10));
    TEST_ASSERT_EQUAL_INT(22, price(2, 12, 10));
    TEST_ASSERT_EQUAL_INT(50, price(2, 40, 10));
}
void test_price_neg(void) {
    TEST_ASSERT_EQUAL_INT(0, price(2, 1, -1));
    TEST_ASSERT_EQUAL_INT(0, price(2, -1, 1));
    TEST_ASSERT_EQUAL_INT(0, price(-2, 1, 1));
}
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_price);
    RUN_TEST(test_price_neg);

    return UNITY_END();
}
