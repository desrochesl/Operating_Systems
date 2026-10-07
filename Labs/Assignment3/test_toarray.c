#include "unity.h"  // For Unity Unit Tests
#include <stdlib.h> // For malloc/free
#include "list.h"

// NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!

/** A list that contains just 10 */
static struct ll_node list_10[] = { { .data = 10, .next = NULL } };

/** A list that contains 10, 11 */
static struct ll_node list_10_11[] = {
        { .data = 10, .next = &(list_10_11[1]) },
        { .data = 11, .next = NULL }
};

/** A list that contains 10, 12, 13, and 11 (in that order) */
static struct ll_node list_10_12_13_11[] = {
        { .data = 10, .next = &(list_10_12_13_11[2]) },
        { .data = 11, .next = NULL },
        { .data = 12, .next = &(list_10_12_13_11[3]) },
        { .data = 13, .next = &(list_10_12_13_11[1]) }
};

/** Global variable to hold the array you just created */
static int* array = NULL;

void setUp(void) {
    // Make sure array is properly set to NULL before do we anything
    array = NULL;
}
void tearDown(void) {
    // Make sure we properly free the array
    if(array) {
        free(array);
        array = NULL;
    }
}

void test_toarray_NULL(void) {
    TEST_ASSERT_NULL(array = ll_toarray(NULL));
}

void test_toarray_10(void) {
    int expected[] = {10};
    array = ll_toarray(list_10);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 1);
}
void test_toarray_10_11(void) {
    int expected[] = {10, 11};
    array = ll_toarray(list_10_11);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}
void test_toarray_10_12_13_11(void) {
    int expected[] = {10, 12, 13, 11};
    array = ll_toarray(list_10_12_13_11);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 4);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_toarray_NULL);
    RUN_TEST(test_toarray_10);
    RUN_TEST(test_toarray_10_11);
    RUN_TEST(test_toarray_10_12_13_11);

    return UNITY_END();
}

