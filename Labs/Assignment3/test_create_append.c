#include <stdlib.h> // For malloc/free
#include "unity.h"  // For Unity Unit Tests
#include "list.h"

/** Global variable to hold the list you just created */
static struct ll_node* list = NULL;
/** Global variable to hold the array used to check the contents */
static int* array = NULL;

void setUp(void) {
    // Make sure list and array is properly set to NULL before do we anything
    list = NULL;
    array = NULL;
}
void tearDown(void) {
    // Make sure we properly free the list
    ll_destroy(list);
    list = NULL;

    // Make sure we properly free the array
    if(array) {
        free(array);
        array = NULL;
    }
}

void test_create_98(void) {
    list = ll_create(9);
    ll_append(list, 8);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {9, 8};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}
void test_create_2021(void) {
    list = ll_create(20);
    ll_append(list, 21);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {20, 21};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}
void test_create_9876(void) {
    list = ll_create(9);
    ll_append(list, 8);
    ll_append(list, 7);
    ll_append(list, 6);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {9, 8, 7, 6};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 4);
}
void test_create_9876543210(void) {
    list = ll_create(9);
    ll_append(list, 8);
    ll_append(list, 7);
    ll_append(list, 6);
    ll_append(list, 5);
    ll_append(list, 4);
    ll_append(list, 3);
    ll_append(list, 2);
    ll_append(list, 1);
    ll_append(list, 0);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 10);
}
void test_create_55555(void) {
    list = ll_create(5);
    ll_append(list, 5);
    ll_append(list, 5);
    ll_append(list, 5);
    ll_append(list, 5);
    ll_append(list, 5);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {5, 5, 5, 5, 5};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 5);
}
void test_create_55(void) {
    list = ll_create(5);
    ll_append(list, 5);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {5, 5};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_98);
    RUN_TEST(test_create_2021);
    RUN_TEST(test_create_9876);
    RUN_TEST(test_create_9876543210);
    RUN_TEST(test_create_55555);
    RUN_TEST(test_create_55);

    return UNITY_END();
}

