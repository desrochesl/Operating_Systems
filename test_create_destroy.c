#include <stdlib.h> // For malloc/free
#include "unity.h"  // For Unity Unit Tests
#include "list.h"

/** Global variable to hold the list you just created */
static struct ll_node* list = NULL;

void setUp(void) {
    // Make sure list is properly set to NULL before do we anything
    list = NULL;
}
void tearDown(void) {
    // Make sure we properly free the list
    ll_destroy(list);
    list = NULL;
}

void test_create_10(void) {
    list = ll_create(10);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_EQUAL_INT(10, ll_head(list)->data);
    TEST_ASSERT_EQUAL_INT(1, ll_size(list));

    // Destroy called in `tearDown`
}
void test_create_20(void) {
    list = ll_create(20);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_EQUAL_INT(20, ll_head(list)->data);
    TEST_ASSERT_EQUAL_INT(1, ll_size(list));

    // Destroy called in `tearDown`
}
void test_create_9(void) {
    list = ll_create(9);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_EQUAL_INT(9, ll_head(list)->data);
    TEST_ASSERT_EQUAL_INT(1, ll_size(list));

    // Destroy called in `tearDown`
}
void test_create_67(void) {
    // Manually create a list of 2 nodes
    struct ll_node* n1 = ll_create(6);
    struct ll_node* n2 = ll_create(7);

    // Link them to the global `list`
    list = n1;
    n1->next = n2;

    // Destroy called in `tearDown`
}
void test_create_678(void) {
    // Manually create a list of 3 nodes
    struct ll_node* n1 = ll_create(6);
    struct ll_node* n2 = ll_create(7);
    struct ll_node* n3 = ll_create(8);

    // Link them to the global `list`
    list = n1;
    n1->next = n2;
    n2->next = n3;

    // Destroy called in `tearDown`
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_10);
    RUN_TEST(test_create_20);
    RUN_TEST(test_create_9);

    RUN_TEST(test_create_67);
    RUN_TEST(test_create_678);
    return UNITY_END();
}

