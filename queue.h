#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Defines a node in the queue, which contains a void pointer
 *
 */
typedef struct node
{
    void *        data;
    struct node * next;
} node_t;

/**
 * @brief Queue structure that contains a pointer to the head and tail nodes,
 * as well as a size variable
 *
 */
typedef struct queue_t
{
    node_t * head;
    node_t * tail;
    size_t   size;
} queue_t;

/**
 * @brief Creates and initializes a queue data structure.
 *
 * @return queue_t*
 */
queue_t * queue_create();

/**
 * @brief Destroy's the queue by freeing each node and finally freeing the
 * queue.
 *
 * @param queue
 * @return int 0=success 1=failure
 */
int queue_destroy(queue_t * queue);

/**
 * @brief Adds a new node at the end of the queue.
 *
 * @param queue
 * @param data
 */
void queue_enqueue(queue_t * queue, void * data);

/**
 * @brief Take the first node in the queue.
 *
 * @param queue
 * @return void*
 */
void * queue_dequeue(queue_t * queue);

/**
 * @brief Checks if a give data value is present in the queue.
 *
 * @param queue
 * @param data
 * @return true
 * @return false
 */
bool queue_contains(queue_t * queue, void * data);

/**
 * @brief Print function for integers
 *
 * @param queue
 */
void print_integer_queue(queue_t * queue);

/**
 * @brief Print function for strings.
 *
 * @param queue
 */
void print_char_queue(queue_t * queue);

/**
 * @brief Gets the nth item in the queue/list.
 *
 * @param queue
 * @param n
 * @return void*
 */
void * queue_get_nth_item(queue_t * queue, int n);

/**
 * @brief Removes an integer item from the queue
 *
 * @param queue
 * @param p_value
 * @return int 0=success 1=failure
 */
int int_queue_remove(queue_t * queue, void * p_value);

/**
 * @brief Removes a string item from the queue
 *
 * @param queue
 * @param p_value
 * @return int 0=success 1=failure
 */
int char_queue_remove(queue_t * queue, void * p_value);

/**
 * @brief Removes every node in the queue by calling queue_dequeue function.
 *
 * @param queue
 */
void remove_all(queue_t * queue);

#endif