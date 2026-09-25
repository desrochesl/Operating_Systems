#include "unity.h"  // For Unity Unit Tests

// Function declaration so that we can use them here
int add_all_pos(int* array, int alen);

void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}

void test_add_all_pos_11_12_13(void) {
    int array[] = {11, 12, 13};
    TEST_ASSERT_EQUAL_INT(36, add_all_pos(array, 3));
}

void test_add_all_pos_11_21_31_41(void) {
    int array[] = {11, 21, 31, 41};
    TEST_ASSERT_EQUAL_INT(104, add_all_pos(array, 4));
}

void test_add_all_pos_11_n12(void) {
    int array[] = {11, -12};
    TEST_ASSERT_EQUAL_INT(11, add_all_pos(array, 2));
}
void test_add_all_pos_null(void) {
    TEST_ASSERT_EQUAL_INT(0, add_all_pos(NULL, 0));
}
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_all_pos_11_12_13);
    RUN_TEST(test_add_all_pos_11_21_31_41);
    RUN_TEST(test_add_all_pos_11_n12);
    RUN_TEST(test_add_all_pos_null);

    return UNITY_END();
}


