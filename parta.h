#pragma once

#include <stdbool.h> // For true/false
#include <stdlib.h> // For malloc/free

enum { OWNER_NOBODY = -1 };

struct mem_region {
    int size;
    int owner;
    struct mem_region* next;
};

struct mem_region* mem_region_init(int size);
int mem_region_length(struct mem_region* regions);
struct mem_region* mem_region_at(struct mem_region* regions, int idx);
void mem_region_term(struct mem_region* regions);

void mem_region_assign(struct mem_region* regions, int requester, int size);
void mem_region_merge_empty(struct mem_region* regions);

void mem_region_alloc(struct mem_region* regions, int requester, int size);
void mem_region_free(struct mem_region* regions, int owner);

