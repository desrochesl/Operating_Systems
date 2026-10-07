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

void test_rm9from9(void) {
    // Given
    int orig[] = {9};
    list = ll_fromarray(orig, 1);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 9);
    TEST_ASSERT_NULL(newhead);
    list = newhead;

    // Then
    TEST_ASSERT_NULL(list);
}
void test_rm6from9(void) {
    // Given
    int orig[] = {9};
    list = ll_fromarray(orig, 1);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 6);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {9};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 1);
}

void test_rm7from987(void) {
    // Given
    int orig[] = {9, 8, 7};
    list = ll_fromarray(orig, 3);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 7);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {9, 8};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}
void test_rm8from987(void) {
    // Given
    int orig[] = {9, 8, 7};
    list = ll_fromarray(orig, 3);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 8);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {9, 7};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}
void test_rm9from987(void) {
    // Given
    int orig[] = {9, 8, 7};
    list = ll_fromarray(orig, 3);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 9);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {8, 7};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 2);
}

void test_rm0from987(void) {
    // Given
    int orig[] = {9, 8, 7};
    list = ll_fromarray(orig, 3);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 0);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {9, 8, 7};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 3);
}

void test_rm7from9879(void) {
    // Given
    int orig[] = {9, 8, 7, 9};
    list = ll_fromarray(orig, 4);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 7);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {9, 8, 9};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 3);
}
void test_rm8from9879(void) {
    // Given
    int orig[] = {9, 8, 7, 9};
    list = ll_fromarray(orig, 4);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 8);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {9, 7, 9};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 3);
}
void test_rm9from9879(void) {
    // Given
    int orig[] = {9, 8, 7, 9};
    list = ll_fromarray(orig, 4);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 9);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {8, 7, 9};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 3);
}

void test_rm0from9879(void) {
    // Given
    int orig[] = {9, 8, 7, 9};
    list = ll_fromarray(orig, 4);
    TEST_ASSERT_NOT_NULL(list);

    // When
    struct ll_node* newhead = ll_remove(list, 0);
    TEST_ASSERT_NOT_NULL(newhead);
    list = newhead;

    // Then
    array = ll_toarray(list);
    int expected[] = {9, 8, 7, 9};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 4);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_rm9from9);
    RUN_TEST(test_rm6from9);
    RUN_TEST(test_rm7from987);
    RUN_TEST(test_rm8from987);
    RUN_TEST(test_rm9from987);
    RUN_TEST(test_rm0from987);
    RUN_TEST(test_rm7from9879);
    RUN_TEST(test_rm8from9879);
    RUN_TEST(test_rm9from9879);
    RUN_TEST(test_rm0from9879);

    return UNITY_END();
}

