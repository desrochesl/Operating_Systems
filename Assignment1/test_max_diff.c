#include "unity.h"  // For Unity Unit Tests

// Function declaration so that we can use them here
int max_diff(int* array, int alen);

void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}

void test_max_diff_null(void) {
    TEST_ASSERT_EQUAL_INT(0, max_diff(NULL, 0));
}
void test_max_diff_11_12(void) {
    int array[] = {11, 12};
    TEST_ASSERT_EQUAL_INT(1, max_diff(array, 2));
}
void test_max_diff_11_12_13_14(void) {
    int array[] = {11, 12, 13, 14};
    TEST_ASSERT_EQUAL_INT(3, max_diff(array, 4));
}
void test_max_diff_11_21_31(void) {
    int array[] = {11, 21, 31};
    TEST_ASSERT_EQUAL_INT(20, max_diff(array, 3));
}
void test_max_diff_11(void) {
    int array[] = {11};
    TEST_ASSERT_EQUAL_INT(0, max_diff(array, 1));
}
void test_max_diff_neg(void) {
    int array[] = {-11, -12, -13, -14};
    TEST_ASSERT_EQUAL_INT(3, max_diff(array, 4));
}
void test_max_diff_neg_11_12_13_14(void) {
    int array[] = {-11, -12, -13, -14};
    TEST_ASSERT_EQUAL_INT(3, max_diff(array, 4));
}
void test_max_diff_neg_11_12_13_14_15(void) {
    int array[] = {-11, -12, -13, -14, -15};
    TEST_ASSERT_EQUAL_INT(4, max_diff(array, 5));
}
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_max_diff_null);
    RUN_TEST(test_max_diff_11_12);
    RUN_TEST(test_max_diff_11_12_13_14);
    RUN_TEST(test_max_diff_11_21_31);
    RUN_TEST(test_max_diff_11);
    RUN_TEST(test_max_diff_neg);
    RUN_TEST(test_max_diff_neg_11_12_13_14);
    RUN_TEST(test_max_diff_neg_11_12_13_14_15);

    return UNITY_END();
}


