#include <stdlib.h> // For malloc/free
#include "unity.h"  // For Unity Unit Tests

void string_fill(char* dest, int dest_cap, char c);

void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}
void test_string_fill_2s(void) {
    // A dest buffer of 2 characters results in a string of 1 Ss
    char dest[] = {'?', '?'};
    string_fill(dest, 2, 'S');
    TEST_ASSERT_EQUAL_STRING_LEN("S", dest, 2);
}

void test_string_fill_2pound(void) {
    // A dest buffer of 3 characters results in a string of 2 #s
    char dest[] = {'?', '?', '?'};
    string_fill(dest, 3, '#');
    TEST_ASSERT_EQUAL_STRING_LEN("##", dest, 3);
}

void test_string_fill_9r(void) {
    // A dest buffer of 9 characters results in a string of 8 Rs
    char dest[] = {'?', '?', '?', '?', '?', '?', '?', '?', '?'};
    string_fill(dest, 9, 'R');
    TEST_ASSERT_EQUAL_STRING_LEN("RRRRRRRR", dest, 9);
}

void test_string_fill_1g(void) {
    // A dest buffer of 1 characters results in a string of no Gs
    char dest[] = {'?'};
    string_fill(dest, 1, 'G');
    TEST_ASSERT_EQUAL_STRING_LEN("", dest, 1);
}

void test_string_fill_zero_cap(void) {
    // A dest buffer of 0 characters should do nothing
    char dest[] = {'?'};
    string_fill(dest, 0, 'X');
    TEST_ASSERT_EQUAL_CHAR('?', dest[0]); // Should remain unchanged
}

void test_string_fill_null(void) {
    // If `dest` is NULL, do nothing
    string_fill(NULL, 0, 'X');
}


int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_string_fill_2s);
    RUN_TEST(test_string_fill_2pound);
    RUN_TEST(test_string_fill_9r);
    RUN_TEST(test_string_fill_1g);
    RUN_TEST(test_string_fill_zero_cap);
    RUN_TEST(test_string_fill_null);

    return UNITY_END();
}

