#include "unity.h"  // For Unity Unit Tests
#include "parta.h"

static struct mem_region* regions = NULL;

void setUp(void) {
    // Code to execute at test start up
    regions = NULL;
}
void tearDown(void) {
    // Code to execute at test conclusion
    mem_region_term(regions);
}

void test_init128(void) {
    // Given
    regions = mem_region_init(128);

    // Then
    TEST_ASSERT_NOT_NULL(regions);
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_ASSERT_EQUAL_INT(128, regions->size);
    TEST_ASSERT_EQUAL_INT(OWNER_NOBODY, regions->owner);

}
/**
 * Initialize a mem region of size 2.
 * NOTE: You should NOT malloc 2 bytes, you malloc a linked-list
 * node that *represents* 2 bytes!
 */
void test_init2(void) {
    // Given
    regions = mem_region_init(2);

    // Then
    TEST_ASSERT_NOT_NULL(regions);
    TEST_ASSERT_EQUAL_INT(1, mem_region_length(regions));
    TEST_ASSERT_EQUAL_INT(2, regions->size);
    TEST_ASSERT_EQUAL_INT(OWNER_NOBODY, regions->owner);
}

void test_init_multiple(void) {
    // When
    struct mem_region* r1 = mem_region_init(128);
    struct mem_region* r2 = mem_region_init(64);
    TEST_ASSERT_NOT_NULL(r1);
    TEST_ASSERT_NOT_NULL(r2);

    // Create the linked list with the pieces
    regions = r1;
    r1->next = r2;

    // Then
    TEST_ASSERT_EQUAL_INT(2, mem_region_length(regions));
}
void test_init_invalid(void) {
    TEST_ASSERT_NULL(mem_region_init(0));
    TEST_ASSERT_NULL(mem_region_init(-1));
    TEST_ASSERT_NULL(mem_region_init(-2));

    TEST_ASSERT_EQUAL_INT(0, mem_region_length(NULL));
    mem_region_term(NULL);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_init128);
    RUN_TEST(test_init2);
    RUN_TEST(test_init_multiple);
    RUN_TEST(test_init_invalid);

    return UNITY_END();
}

