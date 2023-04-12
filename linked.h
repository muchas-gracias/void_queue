#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct node {
    void *data;
    struct node *next;
} node_t;

typedef struct linked_list {
    node_t *head;
    node_t *tail;
} linked_list_t;

linked_list_t *list_create();

void list_destroy(linked_list_t *list);

void list_enqueue(linked_list_t *list, void *data);

void *list_dequeue(linked_list_t *list);

void list_print(linked_list_t *list);

#endif