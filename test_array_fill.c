#include "unity.h"  // For Unity Unit Tests

int array_fill(int *array, int array_len, int begin, int end);

void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}

enum { DUMMY = 99999 };

void test_array_fill_11_12(void) {
    // Fill array initially with dummy values
    int array[] = {DUMMY, DUMMY};

    // Try to fill it
    int returned_size = array_fill(array, 2, 11, 12);

    // Verify results
    TEST_ASSERT_EQUAL_INT(2, returned_size);
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){11, 12}), array, 2);
}
void test_array_fill_11_12_13_14(void) {
    // Fill array initially with dummy values
    int array[] = {DUMMY, DUMMY, DUMMY, DUMMY};

    // Try to fill it
    int returned_size = array_fill(array, 4, 11, 14);

    // Verify results
    TEST_ASSERT_EQUAL_INT(4, returned_size);
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){11, 12, 13, 14}), array, returned_size);
}


void test_array_fill_11_12_13_14_x_x(void) {
    // Fill array initially with dummy values
    int array[] = {DUMMY, DUMMY, DUMMY, DUMMY, DUMMY, DUMMY};

    // Try to PARTIALLY fill it
    int returned_size = array_fill(array, 6, 11, 14);

    // Verify results
    TEST_ASSERT_EQUAL_INT(4, returned_size);
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){11, 12, 13, 14}), array, returned_size);
    TEST_ASSERT_EQUAL_INT(DUMMY, array[4]);  // Do not fill array[4]. Should be kept as DUMMY
    TEST_ASSERT_EQUAL_INT(DUMMY, array[5]);  // Do not fill array[5]. Should be kept as DUMMY
}
void test_array_fill_11_11(void) {
    // Fill array initially with dummy values
    int array[] = {DUMMY, DUMMY};

    // Try to fill it
    int returned_size = array_fill(array, 2, 11, 11);

    // Verify results
    TEST_ASSERT_EQUAL_INT(1, returned_size);
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){11}), array, returned_size);
}

void test_array_fill_nospace(void) {
    // Fill array initially with dummy values
    int array[] = {DUMMY, DUMMY};

    // Try to fill it, but we run out of space
    int returned_size = array_fill(array, 2, 11, 14);

    // Verify results
    TEST_ASSERT_EQUAL_INT(2, returned_size);
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){11, 12}), array, returned_size);
}

void test_array_fill_null(void) {
    // Handle NULL pointer
    TEST_ASSERT_EQUAL_INT(0, array_fill(NULL, 0, 11, 14));

    // Handle incorrect array_len pointer
    int array[] = {DUMMY, DUMMY};
    TEST_ASSERT_EQUAL_INT(0, array_fill(array, 0, 11, 14));
}

void test_array_fill_14_11(void) {
    // Fill array initially with dummy values
    int array[] = {DUMMY, DUMMY};

    // Try to fill with begin larger than end
    int returned_size = array_fill(array, 2, 14, 11);

    // Verify results
    TEST_ASSERT_EQUAL_INT(0, returned_size);
    TEST_ASSERT_EQUAL_INT(DUMMY, array[0]); // Array should remain unchanged
}

void test_array_fill_n2_1(void) {
    // Fill array initially with dummy values
    int array[] = {DUMMY, DUMMY, DUMMY, DUMMY};

    // Try to fill with negative numbers as well
    int returned_size = array_fill(array, 4, -2, 1);

    // Verify results
    TEST_ASSERT_EQUAL_INT(4, returned_size);
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){-2, -1, 0, 1}), array, returned_size);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_array_fill_11_12);
    RUN_TEST(test_array_fill_11_12_13_14);
    RUN_TEST(test_array_fill_11_12_13_14_x_x);
    RUN_TEST(test_array_fill_11_11);
    RUN_TEST(test_array_fill_null);
    RUN_TEST(test_array_fill_14_11);
    RUN_TEST(test_array_fill_n2_1);

    return UNITY_END();
}

