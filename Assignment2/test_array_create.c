#include <stdlib.h> // For malloc/free
#include "unity.h"  // For Unity Unit Tests

int* array_create_evens(int begin, int end);

/// Global variable to hold the array you just created
int* array = NULL;

void setUp(void) {
    // Make sure array is properly set to NULL before do we anything
    array = NULL;
}

void tearDown(void) {
    // Make sure we properly free the array
    if(array != NULL) {
        free(array);
        array = NULL;
    }
}

void test_array_create_evens_11_12(void) {
    array = array_create_evens(11, 12);

    // Verify results
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){12}), array, 1);

    // no need to free (will be done in tearDown() above)
}
void test_array_create_evens_11_14(void) {
    array = array_create_evens(11, 14);

    // Verify results
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){12, 14}), array, 2);

    // no need to free (will be done in tearDown() above)
}

void test_array_create_evens_8_14(void) {
    array = array_create_evens(8, 14);

    // Verify results
    TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){8, 10, 12, 14}), array, 4);

    // no need to free (will be done in tearDown() above)
}

void test_array_create_evens_null(void) {
    array = array_create_evens(11, 11);
    TEST_ASSERT_NULL(array);

    array = array_create_evens(13, 13);
    TEST_ASSERT_NULL(array);

    array = array_create_evens(13, 12);
    TEST_ASSERT_NULL(array);

    array = array_create_evens(13, 9);
    TEST_ASSERT_NULL(array);

    array = array_create_evens(20, 10);
    TEST_ASSERT_NULL(array);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_array_create_evens_11_12);
    RUN_TEST(test_array_create_evens_11_14);
    RUN_TEST(test_array_create_evens_8_14);
    RUN_TEST(test_array_create_evens_null);

    return UNITY_END();
}

