#include "unity.h"  // For Unity Unit Tests

// Function declaration so that we can use them here
int power(int x, int y);


void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}
void test_power(void) {
    TEST_ASSERT_EQUAL_INT(2, power(2, 1));
    TEST_ASSERT_EQUAL_INT(8, power(2, 3));
    TEST_ASSERT_EQUAL_INT(64, power(2, 6));

    TEST_ASSERT_EQUAL_INT(3, power(3, 1));
    TEST_ASSERT_EQUAL_INT(27, power(3, 3));
    TEST_ASSERT_EQUAL_INT(81, power(3, 4));

    TEST_ASSERT_EQUAL_INT(1, power(2, 0));
    TEST_ASSERT_EQUAL_INT(1, power(3, 0));
}
void test_power_neg(void) {
    TEST_ASSERT_EQUAL_INT(0, power(2, -1));
    TEST_ASSERT_EQUAL_INT(0, power(3, -1));
    TEST_ASSERT_EQUAL_INT(0, power(-2, 1));
    TEST_ASSERT_EQUAL_INT(0, power(-3, 1));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_power);
    RUN_TEST(test_power_neg);

    return UNITY_END();
}
