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

void test_find_NULL_11(void) {
    struct ll_node* h = ll_find(NULL, 11);
    TEST_ASSERT_NULL(h);
}
void test_find_NULL_21(void) {
    struct ll_node* h = ll_find(NULL, 21);
    TEST_ASSERT_NULL(h);
}
void test_find_10_10(void) {
    struct ll_node* h = ll_find(list_10, 10);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(10, h->data);
}
void test_find_10_11(void) {
    struct ll_node* h = ll_find(list_10, 11);
    TEST_ASSERT_NULL(h);
}
void test_find_10_21(void) {
    struct ll_node* h = ll_find(list_10, 21);
    TEST_ASSERT_NULL(h);
}
void test_find_10_11_10(void) {
    struct ll_node* h = ll_find(list_10_11, 10);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(10, h->data);
}
void test_find_10_11_11(void) {
    struct ll_node* h = ll_find(list_10_11, 11);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(11, h->data);
}
void test_find_10_11_21(void) {
    struct ll_node* h = ll_find(list_10_11, 21);
    TEST_ASSERT_NULL(h);
}
void test_find_10_13_11_12_10(void) {
    struct ll_node* h = ll_find(list_10_13_11_12, 10);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(10, h->data);
}
void test_find_10_13_11_12_11(void) {
    struct ll_node* h = ll_find(list_10_13_11_12, 11);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(11, h->data);
}
void test_find_10_13_11_12_12(void) {
    struct ll_node* h = ll_find(list_10_13_11_12, 12);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(12, h->data);
}
void test_find_10_13_11_12_13(void) {
    struct ll_node* h = ll_find(list_10_13_11_12, 13);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(13, h->data);
}
void test_find_10_13_11_12_21(void) {
    struct ll_node* h = ll_find(list_10_13_11_12, 21);
    TEST_ASSERT_NULL(h);
}
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_find_NULL_11);
    RUN_TEST(test_find_NULL_21);
    RUN_TEST(test_find_10_10);
    RUN_TEST(test_find_10_11);
    RUN_TEST(test_find_10_21);
    RUN_TEST(test_find_10_11_10);
    RUN_TEST(test_find_10_11_11);
    RUN_TEST(test_find_10_11_21);
    RUN_TEST(test_find_10_13_11_12_10);
    RUN_TEST(test_find_10_13_11_12_11);
    RUN_TEST(test_find_10_13_11_12_12);
    RUN_TEST(test_find_10_13_11_12_13);
    RUN_TEST(test_find_10_13_11_12_21);

    return UNITY_END();
}

