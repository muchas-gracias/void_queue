#include "linked.h"

int main()
{
    int *num0 = NULL;
    int *num1 = NULL;

    char *value0 = NULL;
    char *value1 = NULL;


    linked_list_t *list = list_create();
    if(NULL == list)
    {
        goto ERROR;
    }

    num0 = calloc(1, sizeof(int));
    if(NULL == num0)
    {
        goto DESTROY;
    }
    *num0 = 55;

    num1 = calloc(1, sizeof(int));
    if(NULL == num1)
    {
        free(num0);
        goto DESTROY;
    }
    *num1 = 155;

    value0 = "example";
    value0 = calloc(1, sizeof(char));
    if(NULL == value0)
    {
        free(num0);
        free(num1);
        goto DESTROY;
    }

    value1 = "another example";
    value1 = calloc(1, sizeof(char));
    if(NULL == value1)
    {
        free(num0);
        free(num1);
        free(value0);
        goto DESTROY;
    }


    list_enqueue(list, num0);
    list_enqueue(list, num1);
    list_enqueue(list, value0);
    list_enqueue(list, value1);

    list_destroy(list);
    free(num0);
    free(num1);
    free(value0);
    free(value1);
    goto SUCCESS;



DESTROY:
    list_destroy(list);

ERROR:
    exit(EXIT_FAILURE);

SUCCESS:
    exit(EXIT_SUCCESS);
}