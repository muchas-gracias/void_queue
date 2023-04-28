#ifndef QUEUE_H
#define QUEUE_H

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
    size_t size;
} queue_t;

queue_t *queue_create();

void queue_destroy(queue_t *queue);

void queue_enqueue(queue_t *queue, void *data);

void *queue_dequeue(queue_t *queue);

bool queue_contains(queue_t *queue, void *data);

void print_integer_queue(queue_t *queue);

void print_char_queue(queue_t *queue);

void* queue_get_nth_item(queue_t* queue, int n);

void int_queue_remove(queue_t *queue, void *p_value);

void char_queue_remove(queue_t *queue, void *p_value);

void remove_all(queue_t *queue);

#endif