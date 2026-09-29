#include <stdlib.h> // For malloc/free
#include "unity.h"  // For Unity Unit Tests
char* capitalize(const char* s);

/// Global variable to hold the string you just created
char* capitalized = NULL;

void setUp(void) {
    // Make sure string is properly set to NULL before do we anything
    capitalized = NULL;
}
void tearDown(void) {
    // Make sure we properly free the string
    if(capitalized != NULL) {
        free(capitalized);
        capitalized = NULL;
    }
}
void test_capitalize_abc(void) {
    capitalized = capitalize("abc");
    TEST_ASSERT_EQUAL_STRING_LEN("ABC", capitalized, 4);
    // no need to free (will be done in tearDown() above)
}
void test_capitalize_ABC(void) {
    capitalized = capitalize("ABC");
    TEST_ASSERT_EQUAL_STRING_LEN("ABC", capitalized, 4);
    // no need to free (will be done in tearDown() above)
}
void test_capitalize_ABC_def(void) {
    capitalized = capitalize("ABC_def");
    TEST_ASSERT_EQUAL_STRING_LEN("ABC_DEF", capitalized, 8);
    // no need to free (will be done in tearDown() above)
}
void test_capitalize_ABC_xyz(void) {
    capitalized = capitalize("ABC#xyZ");
    TEST_ASSERT_EQUAL_STRING_LEN("ABC#XYZ", capitalized, 8);
    // no need to free (will be done in tearDown() above)
}
void test_capitalize_empty(void) {
    capitalized = capitalize("");
    TEST_ASSERT_EQUAL_STRING_LEN("", capitalized, 2);
    // no need to free (will be done in tearDown() above)
}
void test_capitalize_null(void) {
    capitalized = capitalize(NULL);
    TEST_ASSERT_NULL(capitalized);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_capitalize_abc);
    RUN_TEST(test_capitalize_ABC);
    RUN_TEST(test_capitalize_ABC_def);
    RUN_TEST(test_capitalize_ABC_xyz);
    RUN_TEST(test_capitalize_empty);
    RUN_TEST(test_capitalize_null);

    return UNITY_END();
}

