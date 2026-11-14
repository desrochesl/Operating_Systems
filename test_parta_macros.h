#pragma once

/**
 * A special macro function that checks if the specified region is owned by `owner`.
 * If the linked list doesn't have enough entries, calls FAIL.
 *
 * It is written as a macro function so that the test failure points to the correct
 * line.
 *
 * @param regions The linked list of regions
 * @param idx The index of the region to look at
 * @param owner The owner ID of the region we looked at
 * @param size The size of the region we looked at
 */
#define TEST_REGION_EQ(_regions, _idx, _owner, _size) do {              \
    TEST_ASSERT_NOT_NULL(regions);                                      \
    struct mem_region* _r = mem_region_at(_regions, _idx);              \
    TEST_ASSERT_NOT_NULL_MESSAGE(_r, "region at index doesn't exist");  \
    TEST_ASSERT_EQUAL_INT(_owner, _r->owner);                           \
    TEST_ASSERT_EQUAL_INT(_size, _r->size);                             \
} while(0)
