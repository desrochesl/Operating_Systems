#include "unity.h"  // For Unity Unit Tests
#include "parta.h"
#include "test_parta_macros.h"

static struct mem_region* regions = NULL;

void setUp(void) {
    // Code to execute at test start up
    regions = mem_region_init(128);
    TEST_ASSERT_NOT_NULL(regions);
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);
}
void tearDown(void) {
    // Code to execute at test conclusion
    mem_region_term(regions);
}

void test_alloc_8(void) {
    // Regions created above (in setUp)

    // When
    mem_region_alloc(regions, 0xA, 8);

    // Then
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, 0xA, 8);
    TEST_REGION_EQ(regions, 1, OWNER_NOBODY, 120);
}

void test_alloc_8_20(void) {
    // Regions created above (in setUp)

    // When
    mem_region_alloc(regions, 0xA, 8);
    mem_region_alloc(regions, 0xB, 20);

    // Then
    TEST_ASSERT_EQUAL_INT(3, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, 0xA, 8);
    TEST_REGION_EQ(regions, 1, 0xB, 20);
    TEST_REGION_EQ(regions, 2, OWNER_NOBODY, 100);
}

void test_alloc_8_20_35(void) {
    // Regions created above (in setUp)

    // When
    mem_region_alloc(regions, 0xA, 8);
    mem_region_alloc(regions, 0xB, 20);
    mem_region_alloc(regions, 0xC, 35);

    // Then
    TEST_ASSERT_EQUAL_INT(4, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, 0xA, 8);
    TEST_REGION_EQ(regions, 1, 0xB, 20);
    TEST_REGION_EQ(regions, 2, 0xC, 35);
    TEST_REGION_EQ(regions, 3, OWNER_NOBODY, 65);
}


int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_alloc_8);
    RUN_TEST(test_alloc_8_20);
    RUN_TEST(test_alloc_8_20_35);

    return UNITY_END();
}

