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
 * Returns the memory region at the specified index, or NULL if the index is out
 * of bounds.
 * @param regions pointer to memory region
 * @param idx index to search for
 * @return memory region at idx
 */
struct mem_region* mem_region_at(struct mem_region* regions, int idx) {
    struct mem_region* region = regions;
    int i = 0;
    while (region != NULL) {
        if (i == idx) return region;
        region = region->next;
        i++;
    }
    return NULL;
}

/**
 * Assigns the specified size to a requester and splits any remaining space into
 * a new unowned region.
 * @param r pointer to memory region
 * @param requester the new owner of r
 * @param size size of mem_region
 */
void mem_region_assign(struct mem_region* r, int requester, int size) {
    if (r == NULL) return;
    int s = r->size - size;
    if (size<0 | size> r->size) return;
    r->owner = requester;
    r->next = mem_region_init(s);
    r->size = size;
    return;
}

/**
 * Merges adjacent unowned memory regions into a single larger region.
 * @param r pointer to memory region
 */
void mem_region_merge_empty(struct mem_region* r) {
    struct mem_region* region = r;
    while (r != NULL) {
        if (r->next == NULL) return;
        struct mem_region* next = r->next;
        if (r->owner == OWNER_NOBODY & next->owner == OWNER_NOBODY) {
            r->size = r->size + next->size;
            r->next = next->next;
            mem_region_free(next, OWNER_NOBODY);
        } else
            r = next;
    }
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

