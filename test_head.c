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

void test_head_NULL(void) {
    struct ll_node* h = ll_head(NULL);
    TEST_ASSERT_NULL(h);
}

void test_head_10(void) {
    struct ll_node* h = ll_head(list_10);

    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(10, h->data);
}
void test_head_10_11(void) {
    struct ll_node* h = ll_head(list_10_11);

    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(10, h->data);
}
void test_head_10_13_11_12(void) {
    struct ll_node* h = ll_head(list_10_13_11_12);

    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(10, h->data);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_head_NULL);
    RUN_TEST(test_head_10);
    RUN_TEST(test_head_10_11);
    RUN_TEST(test_head_10_13_11_12);

    return UNITY_END();
}

