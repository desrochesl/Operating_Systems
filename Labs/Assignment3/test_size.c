#include "unity.h"  // For Unity Unit Tests
#include <stddef.h> // For NULL
#include "list.h"

// NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!

/** A list that contains just 10 */
static struct ll_node list_10[] = { { .data = 10, .next = NULL } };

/** A list that contains 10, 11 */
static struct ll_node list_10_11[] = {
        { .data = 10, .next = &(list_10_11[1]) },
        { .data = 11, .next = NULL }
};

/** A list that contains 10, 13, 11, and 12 (in that order) */
static struct ll_node list_10_13_11_12[] = {
        { .data = 10, .next = &(list_10_13_11_12[3]) },
        { .data = 11, .next = &(list_10_13_11_12[2]) },
        { .data = 12, .next = NULL },
        { .data = 13, .next = &(list_10_13_11_12[1]) }
};

void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}

void test_size_NULL(void) {
    TEST_ASSERT_EQUAL_INT(0, ll_size(NULL));
}

void test_size_10(void) {
    TEST_ASSERT_EQUAL_INT(1, ll_size(list_10));
}
void test_size_10_11(void) {
    TEST_ASSERT_EQUAL_INT(2, ll_size(list_10_11));
}
void test_size_10_13_11_12(void) {
    TEST_ASSERT_EQUAL_INT(4, ll_size(list_10_13_11_12));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_size_NULL);
    RUN_TEST(test_size_10);
    RUN_TEST(test_size_10_11);
    RUN_TEST(test_size_10_13_11_12);

    return UNITY_END();
}

