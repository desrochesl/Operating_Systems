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

void test_from9(void) {
    int orig[] = {9};
    list = ll_fromarray(orig, 1);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {9};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 1);
}
void test_from98(void) {
    int orig[] = {9, 8};
    list = ll_fromarray(orig, 2);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {9, 8};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}
void test_from9876(void) {
    int orig[] = {9, 8, 7, 6};
    list = ll_fromarray(orig, 4);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {9, 8, 7, 6};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 4);
}
void test_from9876543210(void) {
    int orig[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    list = ll_fromarray(orig, 10);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 10);
}
void test_from5(void) {
    int orig[] = {5};
    list = ll_fromarray(orig, 1);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {5};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 1);
}
void test_from55(void) {
    int orig[] = {5, 5};
    list = ll_fromarray(orig, 2);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {5, 5};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}

void test_from55555(void) {
    int orig[] = {5, 5, 5, 5, 5};
    list = ll_fromarray(orig, 5);

    TEST_ASSERT_NOT_NULL(list);
    array = ll_toarray(list);

    int expected[] = {5, 5, 5, 5, 5};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 5);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_from9);
    RUN_TEST(test_from98);
    RUN_TEST(test_from9876);
    RUN_TEST(test_from9876543210);
    
    RUN_TEST(test_from5);
    RUN_TEST(test_from55);
    RUN_TEST(test_from55555);

    return UNITY_END();
}

