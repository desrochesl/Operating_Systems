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

void test_merge_11_22(void) {
    // Given
    struct mem_region* r1 = mem_region_init(11);
    TEST_ASSERT_NOT_NULL(r1);
    struct mem_region* r2 = mem_region_init(22);
    TEST_ASSERT_NOT_NULL(r2);

    // Create the linked list with r1 as head
    regions = r1;
    r1->next = r2;

    // When
    mem_region_merge_empty(regions);

    // Then
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 33);
}
void test_merge_11_22_33(void) {
    // Given
    struct mem_region* r1 = mem_region_init(11);
    TEST_ASSERT_NOT_NULL(r1);
    struct mem_region* r2 = mem_region_init(22);
    TEST_ASSERT_NOT_NULL(r2);
    struct mem_region* r3 = mem_region_init(33);
    TEST_ASSERT_NOT_NULL(r3);

    // Create the linked list with r1 as head
    regions = r1;
    r1->next = r2;
    r2->next = r3;

    // When
    mem_region_merge_empty(regions);

    // Then
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 66);
}
void test_merge_11_22_33_44(void) {
    // Given
    struct mem_region* r1 = mem_region_init(11);
    TEST_ASSERT_NOT_NULL(r1);
    struct mem_region* r2 = mem_region_init(22);
    TEST_ASSERT_NOT_NULL(r2);
    struct mem_region* r3 = mem_region_init(33);
    TEST_ASSERT_NOT_NULL(r3);
    struct mem_region* r4 = mem_region_init(9);
    TEST_ASSERT_NOT_NULL(r4);

    // Create the linked list with r1 as head
    regions = r1;
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;

    // When
    mem_region_merge_empty(regions);

    // Then
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 75);
}

void test_merge_11_empty(void) {
    // Given
    regions = mem_region_init(11);
    TEST_ASSERT_NOT_NULL(regions);

    // When
    mem_region_merge_empty(regions);

    // Then
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 11);
}

void test_merge_11_A(void) {
    // Given
    struct mem_region* r1 = mem_region_init(11);
    TEST_ASSERT_NOT_NULL(r1);
    struct mem_region* r2 = mem_region_init(22);
    TEST_ASSERT_NOT_NULL(r2);
    mem_region_assign(r2, 0xA, 22);

    // Create the linked list with r1 as head
    regions = r1;
    r1->next = r2;

    // When
    mem_region_merge_empty(regions);

    // Then r2 should NOT be merged with r1
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 11);
    TEST_REGION_EQ(regions, 1, 0xA, 22);
}
void test_merge_11_22_A(void) {
    // Given
    struct mem_region* r1 = mem_region_init(11);
    TEST_ASSERT_NOT_NULL(r1);
    struct mem_region* r2 = mem_region_init(22);
    TEST_ASSERT_NOT_NULL(r2);
    struct mem_region* r3 = mem_region_init(33);
    TEST_ASSERT_NOT_NULL(r3);
    mem_region_assign(r3, 0xB, 33);

    // Create the linked list with r1 as head
    regions = r1;
    r1->next = r2;
    r2->next = r3;

    // When
    mem_region_merge_empty(regions);

    // Then r3 should NOT be merged with r2
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 33);
    TEST_REGION_EQ(regions, 1, 0xB, 33);
}

void test_merge_11_22_33_A(void) {
    // Given
    struct mem_region* r1 = mem_region_init(11);
    TEST_ASSERT_NOT_NULL(r1);
    struct mem_region* r2 = mem_region_init(22);
    TEST_ASSERT_NOT_NULL(r2);
    struct mem_region* r3 = mem_region_init(33);
    TEST_ASSERT_NOT_NULL(r3);
    struct mem_region* r4 = mem_region_init(9);
    TEST_ASSERT_NOT_NULL(r4);
    mem_region_assign(r4, 0xC, 9);

    // Create the linked list with r1 as head
    regions = r1;
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;

    // When
    mem_region_merge_empty(regions);

    // Then r4 should NOT be merged with r3
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
    TEST_REGION_EQ(regions, 0, OWNER_NOBODY, 66);
    TEST_REGION_EQ(regions, 1, 0xC, 9);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_merge_11_22);
    RUN_TEST(test_merge_11_22_33);
    RUN_TEST(test_merge_11_22_33_44);
    RUN_TEST(test_merge_11_empty);
    RUN_TEST(test_merge_11_A);
    RUN_TEST(test_merge_11_22_A);
    RUN_TEST(test_merge_11_22_33_A);

    return UNITY_END();
}

