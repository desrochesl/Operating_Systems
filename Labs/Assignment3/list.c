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
 * Searches through the linked list to calculate it's size
 * @param head pointer to the start of the linked list
 * @returns the size of the linked list
 */
int ll_size(struct ll_node *head) {
    struct ll_node *current = head;
    int size = 0;
    while (current != NULL) {
        current = current->next;
        size++;
    }
    return size;
}

/**
 * Searches through the linked list to find the first occurance of a value
 * @param head pointer to the start of the linked list
 * @param value to search for
 * @returns the node containing the value given. else: NULL
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    if (!head) return NULL;
    for (struct ll_node *c = head; c; c = c->next) {
        if (c->data == value) return c;
    }
    return NULL;
}

/**
 * Converts a linked list to an array
 * @param head pointer to the start of the linked list
 * @returns linked list to array
 */
int *ll_toarray(struct ll_node *head) {
    struct ll_node *current = head;
    int size = ll_size(head);
    if (!head || size <= 0) return NULL;

    int *ll_array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        ll_array[i] = current->data;
        current = current->next;
    }
    return ll_array;
}

/**
 * Creates a new linked list node
 * @param data to be insterted into the node
 * @returns node a ll_node containing the given data
 */
struct ll_node *ll_create(int data) {
    struct ll_node *node = malloc(sizeof(struct ll_node));
    if (node) *node = (struct ll_node){.data = data, .next = NULL};

    return node;
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

