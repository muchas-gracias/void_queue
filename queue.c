#include "queue.h"


queue_t *queue_create()
{
    queue_t *queue = calloc(1, sizeof(queue_t));
    if(NULL == queue)
    {
        goto EXIT;
    }

    queue->head = NULL;
    queue->tail = NULL;

    queue->size = 0;
EXIT:
    return queue;
}

void queue_destroy(queue_t *queue)
{
    if(NULL ==  queue)
    {
        perror("Memory Error");
        goto EXIT;
    }

    node_t *current = queue->head;

    while (NULL != current)
    {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
EXIT:
    return;
}

void queue_enqueue(queue_t *queue, void *data)
{
    if(NULL ==  queue)
    {
        perror("Memory Error");
        goto EXIT;
    }

    node_t *new_node = calloc(1, sizeof(node_t));

    if(NULL ==  new_node)
    {
        goto EXIT;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (NULL == queue->tail)
    {
        queue->head = new_node;
    }
    else
    {
        queue->tail->next = new_node;
    }
    queue->tail = new_node;
    queue->size++;

EXIT:
    return;
}



void *queue_dequeue(queue_t * queue)
{
    void *data = NULL;

    if (NULL == queue->head)
    {
        goto EXIT;
    }
    else
    {
        data = queue->head->data;
        node_t *temp = queue->head;
        queue->head = queue->head->next;
        if (NULL == queue->head)
        {
            queue->tail = NULL;
        }
        free(temp);
        queue->size--;
    }
EXIT:
    return NULL == queue->head ? NULL : data;
}

bool queue_contains(queue_t *queue, void *data)
{
    bool b_return_value = false;

    if(NULL ==  queue)
    {
        perror("Memory Error");
        goto EXIT;
    }

    if (NULL == queue || NULL == data)
    {
        goto EXIT;
    }

    node_t *current = queue->head;

    while (NULL != current)
    {
        if (*(int*)current->data == *(int*)data)
        {
            b_return_value = true;
        }
        current = current->next;
    }
EXIT:
    return b_return_value;
}


void print_integer_queue(queue_t *queue)
{
    if ((NULL == queue) || (NULL == queue->head))
    {
        goto EXIT;
    }

    node_t *current = queue->head;
    printf("[");

    while (NULL != current)
    {
        if (NULL != current->data)
        {
            int *value_ptr = (int *)current->data;
            printf("%d", *value_ptr);
        }
        if (NULL != current->next)
        {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
EXIT:
    return;
}

void print_char_queue(queue_t *queue)
{
    char *value_ptr = NULL;
    if ((NULL == queue) || (NULL == queue->head))
    {
        goto EXIT;
    }

    node_t *current = queue->head;
    printf("[");

    while (NULL != current)
    {
        if (NULL != current->data)
        {
            value_ptr = (char *)current->data;
            printf("%s", value_ptr);
        }
        if (NULL != current->next )
        {
            printf(", ");
        }
        current = current->next;
    }

    printf("]\n");
EXIT:
    return;
}


void* queue_get_nth_item(queue_t* queue, int nth)
{
    void* result = NULL;

    if ((NULL == queue) || (nth < 0))
    {
        goto EXIT;
    }

    node_t* current = queue->head;
    int index = 0;

    while (NULL != current && index < nth)
    {
        current = current->next;
        index++;
    }

    if (NULL != current)
    {
        result = current->data;
    }

EXIT:
    return result;
}


void int_queue_remove(queue_t *queue, void *p_value)
{
    int *value = NULL;

    if (NULL == queue)
    {
        goto EXIT;
    }

    if (NULL == p_value)
    {
        goto EXIT;
    }
    //setting to p_value
    value = (int *) p_value;
    //pointing to the head of the queue
    node_t *current = queue->head;
    //holds the previous node
    node_t *previous = NULL;

    //loop to compare current to the data passed into the function
    while (NULL != current)
    {
        if (*(int *)current->data == *value)
        {
            if (NULL == previous)
            {

                queue->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            //at the end of the queue
            if (NULL == current->next)
            {

                queue->tail = previous;
            }

            free(current);
            queue->size--;
            goto EXIT;
        }
        previous = current;
        current = current->next;
    }

EXIT:
    return;
}

void char_queue_remove(queue_t * queue, void * p_value)
{
    char *value = NULL;

    if (NULL == queue)
    {
        goto EXIT;
    }

    if (NULL == p_value)
    {
        goto EXIT;
    }
    //setting to p_value
    value = (char *) p_value;
    //pointing to the head of the queue
    node_t *current = queue->head;
    //holds the previous node
    node_t *previous = NULL;

    //loop to compare current to the data passed into the function
    while (NULL != current)
    {
        if (strncmp((char *)current->data, value, strlen(value)) == 0)
        {
            if (NULL == previous)
            {

                queue->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            //at the end of the queue
            if (NULL == current->next)
            {

                queue->tail = previous;
            }

            free(current);
            queue->size--;
            goto EXIT;
        }
        previous = current;
        current = current->next;
    }
EXIT:
    return;
}

void remove_all(queue_t *queue)
{
    if(NULL == queue)
    {
        goto EXIT;
    }

    while(queue->size > 0)
    {
        queue_dequeue(queue);
    }

EXIT:
    return;
}




