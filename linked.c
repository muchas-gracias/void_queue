#include "linked.h"


linked_list_t *list_create()
{
    linked_list_t *list = calloc(1, sizeof(linked_list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void list_destroy(linked_list_t *list)
{
    node_t *current = list->head;
    while (current != NULL)
    {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

void list_enqueue(linked_list_t *list, void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL)
    {
        list->head = new_node;
    }
    else
    {
        list->tail->next = new_node;
    }
    list->tail = new_node;
}

void *list_dequeue(linked_list_t *list)
{
    if (list->head == NULL)
    {
        return NULL;
    }
    else
    {
        void *data = list->head->data;
        node_t *temp = list->head;
        list->head = list->head->next;
        if (list->head == NULL)
        {
            list->tail = NULL;
        }
        free(temp);
        return data;
    }
}


