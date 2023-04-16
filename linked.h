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

typedef struct linked_list
{
    node_t *head;
    node_t *tail;
} linked_list_t;

linked_list_t *list_create();

void list_destroy(linked_list_t *list);

void list_enqueue(linked_list_t *list, void *data);

void *list_dequeue(linked_list_t *list);

bool list_contains(linked_list_t *list, void *data);

void print_integer_list(linked_list_t *list);

void print_char_list(linked_list_t *list);

void* list_get_nth_item(linked_list_t* list, int n);

void int_list_remove(linked_list_t *list, void *p_value);

void char_list_remove(linked_list_t *list, void *p_value);

#endif