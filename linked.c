#include "linked.h"


linked_list_t *list_create()
{
    linked_list_t *list = calloc(1, sizeof(linked_list_t));
    if(NULL == list)
    {
        goto END;
    }
    list->head = NULL;
    list->tail = NULL;
END:
    return list;
}

void list_destroy(linked_list_t *list)
{
    node_t *current = list->head;
    while (NULL != current)
    {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

void list_enqueue(linked_list_t *list, void *data)
{
    node_t *new_node = calloc(1, sizeof(node_t));
    if(NULL ==  new_node)
    {
        goto END;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (NULL == list->tail)
    {
        list->head = new_node;
    }
    else
    {
        list->tail->next = new_node;
    }
    list->tail = new_node;
END:
    return;
}

void *list_dequeue(linked_list_t *list)
{
    void *data = NULL;

    if (NULL == list->head)
    {
        goto END;
    }
    else
    {
        data = list->head->data;
        node_t *temp = list->head;
        list->head = list->head->next;
        if (NULL == list->head)
        {
            list->tail = NULL;
        }
        free(temp);
    }
END:
    return NULL == list->head ? NULL : data;
}

bool list_contains(linked_list_t *list, void *data)
{
    bool b_return_value = false;

    if (NULL == list || NULL == data)
    {
        goto END;
    }

    node_t *current = list->head;

    while (NULL != current)
    {
        if (*(int*)current->data == *(int*)data)
        {
            b_return_value = true;
        }
        current = current->next;
    }
END:
    return b_return_value;
}


void print_integer_list(linked_list_t *list)
{
    if ((NULL == list) || (NULL == list->head))
    {
        goto END;
    }

    node_t *current = list->head;
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
END:
    return;
}

void print_char_list(linked_list_t *list)
{
    char *value_ptr = NULL;
    if ((NULL == list) || (NULL == list->head))
    {
        goto END;
    }

    node_t *current = list->head;
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
END:
    return;
}


void* list_get_nth_item(linked_list_t* list, int nth)
{
    void* result = NULL;

    if ((NULL == list) || (nth < 0))
    {
        goto END;
    }

    node_t* current = list->head;
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

END:
    return result;
}


void list_remove(linked_list_t *list, void *p_value)
{
    int *value = NULL;

    if (NULL == list)
    {
        goto END;
    }

    if (NULL == p_value)
    {
        goto END;
    }
    //setting to p_value
    value = (int *) p_value;
    //pointing to the head of the linked li st
    node_t *current = list->head;
    //holds the previous node
    node_t *previous = NULL;

    //loop to compare current to the data passed into the function
    while (NULL != current)
    {
        if (*(int *)current->data == *value)
        {
            if (NULL == previous)
            {

                list->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            //at the end of the list
            if (NULL == current->next)
            {

                list->tail = previous;
            }

            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
END:
    return;
}






