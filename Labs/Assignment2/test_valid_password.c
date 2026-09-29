#include "unity.h"  // For Unity Unit Tests
#include <stdbool.h> // For true/false

bool valid_password(const char* s);

void setUp(void) {
    // Code to execute at test start up (currently empty)
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
}
void test_password_length_requirements(void) {
    // Invalid: Too short (5 chars)
    TEST_ASSERT_FALSE(valid_password("aBcD1"));
    
    // Valid: Exactly 6 chars with 2+ lowercase and 2+ uppercase
    TEST_ASSERT_TRUE(valid_password("abCDef"));
    TEST_ASSERT_TRUE(valid_password("abCD12"));
    
    // Valid: Exactly 10 chars with 2+ lowercase and 2+ uppercase
    TEST_ASSERT_TRUE(valid_password("abCDefGH12"));
    TEST_ASSERT_TRUE(valid_password("ABcdEFgh12"));
    
    // Invalid: Too long (11 chars)
    TEST_ASSERT_FALSE(valid_password("abCDefGH123"));
    TEST_ASSERT_FALSE(valid_password("ABcdEFgh123"));
}

void test_letter_case_requirements(void) {
    // Invalid: Only 1 lowercase letter (despite valid length)
    TEST_ASSERT_FALSE(valid_password("aBCDEF"));
    TEST_ASSERT_FALSE(valid_password("a12BCD"));
    
    // Invalid: Only 1 uppercase letter (despite valid length)
    TEST_ASSERT_FALSE(valid_password("Abcdef"));
    TEST_ASSERT_FALSE(valid_password("abcdeF"));
    
    // Invalid: No lowercase letters
    TEST_ASSERT_FALSE(valid_password("ABCDEF"));
    TEST_ASSERT_FALSE(valid_password("ABC123"));
    
    // Invalid: No uppercase letters
    TEST_ASSERT_FALSE(valid_password("abcdef"));
    TEST_ASSERT_FALSE(valid_password("abc123"));
    
    // Valid: Exactly 2 lowercase and 2 uppercase
    TEST_ASSERT_TRUE(valid_password("abCDef"));
    TEST_ASSERT_TRUE(valid_password("ABcd12"));
}

void test_valid_password_with_special_chars(void) {
    TEST_ASSERT_FALSE(valid_password("aB1!eF"));
    TEST_ASSERT_FALSE(valid_password("aB!eF"));
    TEST_ASSERT_FALSE(valid_password("aB1@eF"));
    TEST_ASSERT_FALSE(valid_password("aB@eF"));
}

void test_additional_edge_cases(void) {
    TEST_ASSERT_FALSE(valid_password(NULL));
    TEST_ASSERT_FALSE(valid_password(""));
    
    // Test all digits (invalid - needs lowercase and uppercase)
    TEST_ASSERT_FALSE(valid_password("123456"));
    
    // Test no digits (valid - digits are optional)
    TEST_ASSERT_TRUE(valid_password("abCDef"));
    
    // Test minimum requirements (6 chars, exactly 2 lowercase, 2 uppercase)
    TEST_ASSERT_TRUE(valid_password("abCD12"));
    
    // Test maximum length with minimum case requirements
    TEST_ASSERT_TRUE(valid_password("abCD123456"));
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_password_length_requirements);
    RUN_TEST(test_letter_case_requirements);
    RUN_TEST(test_valid_password_with_special_chars);
    RUN_TEST(test_additional_edge_cases);

    return UNITY_END();
}
