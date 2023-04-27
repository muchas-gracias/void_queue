#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

typedef struct queue_t
{
    node_t *head;
    node_t *tail;
} queue_t;

queue_t *queue_create();

void list_destroy(queue_t *list);

void list_enqueue(queue_t *list, void *data);

void *list_dequeue(queue_t *list);

bool list_contains(queue_t *list, void *data);

void print_integer_list(queue_t *list);

void print_char_list(queue_t *list);

void* list_get_nth_item(queue_t* list, int n);

void int_list_remove(queue_t *list, void *p_value);

void char_list_remove(queue_t *list, void *p_value);

#endif