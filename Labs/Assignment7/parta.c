#include "parta.h"

/**
 * Allocates and initializes a single unowned memory region of the specified
 * size.
 * @param size size of mem_region
 * @return the created mem_region
 */
struct mem_region* mem_region_init(int size) {
    if (size <= 0) return NULL;
    struct mem_region* regions = malloc(sizeof(struct mem_region));
    if (regions == NULL) return NULL;
    regions->next = NULL;
    regions->size = size;
    regions->owner = OWNER_NOBODY;
    return regions;
}

/**
 * Deallocates every memory region in the linked list.
 * @param regions pointer to memory region
 */
void mem_region_term(struct mem_region* regions) {
    while (regions != NULL) {
        struct mem_region* next = regions->next;
        free(regions);
        regions = next;
    }
}

/**
 * Counts and returns the total number of memory regions in the linked list.
 * @param regions pointer to memory region
 * @returns length of regions
 */
int mem_region_length(struct mem_region* regions) {
    struct mem_region* region = regions;
    int i = 0;
    while (region != NULL) {
        i++;
        region = region->next;
    }
    return i;
}

/**
 * TODO: Describe what the function does
 */
struct mem_region* mem_region_at(struct mem_region* regions, int idx) {
    // TODO: Complete and document
    return NULL;
}


/**
 * TODO: Describe what the function does
 */
void mem_region_assign(struct mem_region* r, int requester, int size) {
    // TODO: Complete and document
}

/**
 * TODO: Describe what the function does
 */
void mem_region_merge_empty(struct mem_region* r) {
    // TODO: Complete and document
}

/**
 * TODO: Describe what the function does
 */
void mem_region_alloc(struct mem_region* regions, int requester, int size) {
    // TODO: Complete and document
}

/**
 * TODO: Describe what the function does
 */
void mem_region_free(struct mem_region* regions, int requester) {
    // TODO: Complete and document
}

