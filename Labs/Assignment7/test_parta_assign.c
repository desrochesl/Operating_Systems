#include "unity.h"  // For Unity Unit Tests
#include "parta.h"
#include "test_parta_macros.h"

static struct mem_region* regions = NULL;

void setUp(void) {
    // Code to execute at test start up
    regions = NULL;
}
void tearDown(void) {
    // Code to execute at test conclusion
    mem_region_term(regions);
}

void test_assign_8_128(void) {
    // Given
    regions = mem_region_init(128);
    TEST_ASSERT_NOT_NULL(regions);
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);

    // When
    mem_region_assign(regions, 0xA, 8);

    // Then
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, 0xA, 8);
    TEST_REGION_EQ(regions, 1, OWNER_NOBODY, 120);
}
void test_assign_48_128(void) {
    // Given
    regions = mem_region_init(128);
    TEST_ASSERT_NOT_NULL(regions);
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);

    // When
    mem_region_assign(regions, 0xB, 48);

    // Then
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, 0xB, 48);
    TEST_REGION_EQ(regions, 1, OWNER_NOBODY, 80);
}
void test_assign_128_128(void) {
    // Given
    regions = mem_region_init(128);
    TEST_ASSERT_NOT_NULL(regions);
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);

    // When
    mem_region_assign(regions, 0xA, 128);

    // Then
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, 0xA, 128);
}
void test_assign_130_128(void) {
    // Given
    regions = mem_region_init(128);
    TEST_ASSERT_NOT_NULL(regions);
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);

    // When
    mem_region_assign(regions, 0xA, 130);

    // Then (too large, so leave alone)
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);
}


void test_assign_200_128(void) {
    // Given
    regions = mem_region_init(128);
    TEST_ASSERT_NOT_NULL(regions);
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);

    // When
    mem_region_assign(regions, 0xA, 200);

    // Then (too large, so leave alone)
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);
}

void test_assign_invalid_128(void) {
    // Given
    regions = mem_region_init(128);
    TEST_ASSERT_NOT_NULL(regions);
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);

    // When
    mem_region_assign(regions, 0xA, -1);

    // Then (too large, so leave alone)
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);

    // When
    mem_region_assign(regions, 0xB, -2);

    // Then (too large, so leave alone)
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);

}

void test_assign_NULL(void) {
    // Try to assign to NULL (should not crash)
    mem_region_assign(NULL, 0xA, 8);
    mem_region_assign(NULL, 0xB, 48);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_assign_8_128);
    RUN_TEST(test_assign_48_128);
    RUN_TEST(test_assign_128_128);
    RUN_TEST(test_assign_130_128);
    RUN_TEST(test_assign_200_128);
    RUN_TEST(test_assign_invalid_128);
    RUN_TEST(test_assign_NULL);

    return UNITY_END();
}

