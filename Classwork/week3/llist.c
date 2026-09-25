#include <stdio.h>
#include <stdlib.h>

struct ll_node 
{
    int data;
    struct ll_node *next;
};

int main() 
{
    size_t size_struct = sizeof(struct ll_node);

    struct ll_node *head = malloc(size_struct);

    head->data = 7000;
    head->next = NULL;

    printf("size of our linkedlist is %zu\n", size_struct);
    printf("head is %d\n", head->data);

    // adding the body of the linked list
    struct ll_node *body = malloc(size_struct);
    body->data = 20;
    body->next = NULL;

    head->next = body;

    printf("body of the linked list is: %d", body->data);

    return 0;
}