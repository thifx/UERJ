#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
} linkedList_t;

void push(linkedList_t *, int);
void printList(linkedList_t *);

int main()
{
    linkedList_t *l1;
    l1 = (linkedList_t *)malloc(sizeof(linkedList_t));
    l1->head = NULL;
    l1->tail = NULL;
    push(l1, 4);
    push(l1, 8);
    push(l1, 10);
    push(l1, 14);
    push(l1, 1123);
    printList(l1);
    return 0;
}

void push(linkedList_t *list, int value)
{
    node_t *new_node;
    new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    if (list->head == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void printList(linkedList_t *list)
{
    node_t *curr = list->head;
    while (curr->next != NULL)
    {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
    printf("%d\n", curr->value);
}