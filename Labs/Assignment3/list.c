#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list
 * @param head pointer to the head of the linked list
 * @return a struct version of the head of the linked list
 */
struct ll_node *ll_head(struct ll_node *head) { return head; }

/**
 * Finds the tail of the linked list by gathering the next
 * @param head pointer to the start of the linked list
 * @returns the tail of the linked list
 */
struct ll_node *ll_tail(struct ll_node *head) {
    struct ll_node *current = head;
    int size = ll_size(head);

    if (!head) return NULL;

    for (struct ll_node *c = current; c->next; c = c->next) current = c->next;

    return current;
}

/**
 * TODO: Describe what the function does
 */
int ll_size(struct ll_node *head) {
    // TODO: Complete and document
    return -1;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    // TODO: Complete and document
    return NULL;
}

/**
 * TODO: Describe what the function does
 */
int *ll_toarray(struct ll_node *head) {
    // TODO: Complete and document
    return NULL;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_create(int data) {
    // TODO: Complete and document
    return NULL;
}

/**
 * TODO: Describe what the function does
 */
void ll_destroy(struct ll_node *head) {
    // TODO: Complete and document
}

/**
 * TODO: Describe what the function does
 */
void ll_append(struct ll_node *head, int data) {
    // TODO: Complete and document
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_fromarray(int* data, int len) {
    // TODO: Complete and document
    return NULL;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    // TODO: Complete and document
    return NULL;
}

