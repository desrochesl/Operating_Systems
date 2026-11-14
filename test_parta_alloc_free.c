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

void test_alloc_8_free(void) {
    // Regions created above (in setUp)

    // When
    mem_region_alloc(regions, 0xA, 8);
    mem_region_free(regions, 0xA);

    // Then
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 128);
}

void test_alloc_8_20_free_20(void) {
    // Regions created above (in setUp)

    // When
    mem_region_alloc(regions, 0xA, 8);
    mem_region_alloc(regions, 0xB, 20);
    mem_region_free(regions, 0xB);

    // Then
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, 0xA, 8);
    TEST_REGION_EQ(regions, 1, OWNER_NOBODY, 120);
}
void test_alloc_8_20_free_8(void) {
    // Regions created above (in setUp)

    // When
    mem_region_alloc(regions, 0xA, 8);
    mem_region_alloc(regions, 0xB, 20);
    mem_region_free(regions, 0xA);

    // Then
    TEST_ASSERT_EQUAL_INT(3, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 8);
    TEST_REGION_EQ(regions, 1, 0xB, 20);
    TEST_REGION_EQ(regions, 2, OWNER_NOBODY, 100);
}
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_alloc_8_free);
    RUN_TEST(test_alloc_8_20_free_20);
    RUN_TEST(test_alloc_8_20_free_8);

    return UNITY_END();
}

