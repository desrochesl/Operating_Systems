#include "unity.h"  // For Unity Unit Tests
#include "parta.h"
#include "test_parta_macros.h"

static struct mem_region* regions = NULL;

void setUp(void) {
    // Code to execute at test start up (currently empty)
    regions = NULL;
}
void tearDown(void) {
    // Code to execute at test conclusion (currently empty)
    mem_region_term(regions);
}

void test_at1(void) {
    // When
    struct mem_region* r1 = mem_region_init(32);
    TEST_ASSERT_NOT_NULL(r1);

    // Create the linked list with the pieces
    regions = r1;

    // Then
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_ASSERT_NOT_NULL(mem_region_at(regions, 0));
    TEST_ASSERT_NULL(mem_region_at(regions, 1));
    TEST_ASSERT_NULL(mem_region_at(regions, -1));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 32);
}
void test_at2(void) {
    // When
    struct mem_region* r1 = mem_region_init(32);
    TEST_ASSERT_NOT_NULL(r1);
    struct mem_region* r2 = mem_region_init(64);
    TEST_ASSERT_NOT_NULL(r2);

    // Create the linked list with the pieces
    regions = r1;
    r1->next = r2;

    // Then
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
    TEST_ASSERT_NOT_NULL(mem_region_at(regions, 0));
    TEST_ASSERT_NOT_NULL(mem_region_at(regions, 1));
    TEST_ASSERT_NULL(mem_region_at(regions, 2));
    TEST_ASSERT_NULL(mem_region_at(regions, -1));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 32);
    TEST_REGION_EQ(regions, 1, OWNER_NOBODY, 64);
}
void test_at3(void) {
    // When
    struct mem_region* r1 = mem_region_init(32);
    TEST_ASSERT_NOT_NULL(r1);
    struct mem_region* r2 = mem_region_init(64);
    TEST_ASSERT_NOT_NULL(r2);
    struct mem_region* r3 = mem_region_init(128);
    TEST_ASSERT_NOT_NULL(r3);

    // Create the linked list with the pieces
    regions = r1;
    r1->next = r2;
    r2->next = r3;

    // Then
    TEST_ASSERT_EQUAL_INT(3, mem_region_length(regions));
    TEST_ASSERT_NOT_NULL(mem_region_at(regions, 0));
    TEST_ASSERT_NOT_NULL(mem_region_at(regions, 1));
    TEST_ASSERT_NOT_NULL(mem_region_at(regions, 2));
    TEST_ASSERT_NULL(mem_region_at(regions, 3));
    TEST_ASSERT_NULL(mem_region_at(regions, -1));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 32);
    TEST_REGION_EQ(regions, 1, OWNER_NOBODY, 64);
    TEST_REGION_EQ(regions, 2, OWNER_NOBODY, 128);
}
void test_at_invalid(void) {
    TEST_ASSERT_NULL(mem_region_at(NULL, 0));
    TEST_ASSERT_NULL(mem_region_at(NULL, -1));
}


int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_at1);
    RUN_TEST(test_at2);
    RUN_TEST(test_at3);
    RUN_TEST(test_at_invalid);

    return UNITY_END();
}

