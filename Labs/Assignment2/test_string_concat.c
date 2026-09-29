#include <stdlib.h> // For malloc/free
#include "unity.h"  // For Unity Unit Tests

void string_concat(char* src1, int src1_cap, const char* src2);

void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}
void test_string_concat_empty_ABC(void) {
    // Concat("", "ABC")
    char dest[] = {'\0', '?', '?', '?', '?', '?', '?', '?', '?'};
    string_concat(dest, 9, "ABC");
    TEST_ASSERT_EQUAL_STRING_LEN("ABC", dest, 4);
}
void test_string_concat_ABC_DEF(void) {
    // Concat("ABC", "DEF")
    char dest[9] = {'A', 'B', 'C', '\0', '?', '?', '?', '?', '?'};
    string_concat(dest, 9, "DEF");
    TEST_ASSERT_EQUAL_STRING_LEN("ABCDEF", dest, 7);
}
void test_string_concat_ABC_empty(void) {
    // Concat("ABC", "")
    char dest[9] = {'A', 'B', 'C', '\0', '?', '?', '?', '?', '?'};
    string_concat(dest, 9, "");
    TEST_ASSERT_EQUAL_STRING_LEN("ABC", dest, 4);
}
void test_string_concat_ABC_NULL(void) {
    // Concat("ABC", NULL)
    char dest[9] = {'A', 'B', 'C', '\0', '?', '?', '?', '?', '?'};
    string_concat(dest, 9, NULL);
    TEST_ASSERT_EQUAL_STRING_LEN("ABC", dest, 4);
}

void test_string_concat_ABC_NULL_dest(void) {
    // Concat("ABC", NULL)
    char dest[9] = {'A', 'B', 'C', '\0', '?', '?', '?', '?', '?'};
    string_concat(NULL, 9, "DEF");
    TEST_ASSERT_EQUAL_STRING_LEN("ABC", dest, 4);
}

void test_string_concat_NULL_ABC(void) {
    // Concat(NULL, "DEF")
    string_concat(NULL, 0, NULL);
    // should not crash
}

void test_string_concat_short_ABC_DEF(void) {
    // Concat("ABC", "DEF")
    char dest[9] = {'A', 'B', 'C', '\0', '?'};
    string_concat(dest, 5, "DEF");
    TEST_ASSERT_EQUAL_STRING_LEN("ABCD", dest, 5);
}

void test_string_concat_exact_capacity(void) {
    // Concat("AA", "BB") with capacity 4
    char dest[4] = {'A', 'A', '\0', '?'};
    string_concat(dest, 4, "BB");
    TEST_ASSERT_EQUAL_STRING_LEN("AAB", dest, 4);
}

void test_string_concat_capacity_one(void) {
    // Concat("", "A") with capacity 1
    char dest[1] = {'\0'};
    string_concat(dest, 1, "A");
    TEST_ASSERT_EQUAL_STRING_LEN("", dest, 1);
}

void test_string_concat_already_at_capacity(void) {
    // Concat("ABC", "DEF") with capacity 4
    char dest[4] = {'A', 'B', 'C', '\0'};
    string_concat(dest, 4, "DEF");
    TEST_ASSERT_EQUAL_STRING_LEN("ABC", dest, 4);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_string_concat_empty_ABC);
    RUN_TEST(test_string_concat_ABC_DEF);
    RUN_TEST(test_string_concat_ABC_empty);
    RUN_TEST(test_string_concat_ABC_NULL);
    RUN_TEST(test_string_concat_NULL_ABC);
    RUN_TEST(test_string_concat_short_ABC_DEF);
    RUN_TEST(test_string_concat_exact_capacity);
    RUN_TEST(test_string_concat_capacity_one);
    RUN_TEST(test_string_concat_already_at_capacity);

    return UNITY_END();
}
