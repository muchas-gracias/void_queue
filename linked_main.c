#include "linked.h"

int main()
{
    //inserting ints
    int num0 = 10;
    int num1 = 55;
    int num2 = 87;

    linked_list_t *list = list_create();
    if(NULL == list)
    {
        goto ERROR;
    }

    list_enqueue(list, &num0);
    list_enqueue(list, &num1);
    list_enqueue(list, &num2);
    printf("\nPRINTING FULL LIST...");
    print_integer_list(list);

    int sampl = 807;
    int *result = NULL;

    result = list_get_nth_item(list, 2);
    printf("\nTHE 3RD ITEM IN THE LIST IS %d\n", *result);


    if(true == list_contains(list, &sampl))
    {
        printf("\n%d IS IN THE LIST\n", sampl);
    }
    else
    {
        printf("\n%d IS NOT IN THE LIST\n", sampl);
    }

    int val_to_remove = 87;
    int_list_remove(list, &val_to_remove);

    printf("\nPRINTING FULL LIST...");
    print_integer_list(list);

    list_destroy(list);

// inserting strings
    linked_list_t *llist = list_create();
    if(NULL == llist)
    {
        goto ERROR;
    }
    const char * word = "brent";
    const char * word1 = "davis";
    const char * word2 = "smith";
    const char * word3 = "bill";
    const char * word4 = "davidson";
    const char * word5 = "harley";
    const char * word6 = "bilal";
    const char * word7 = "dirk";
    const char * word8 = "sammy";

    list_enqueue(llist, (char*)word);
    list_enqueue(llist, (char*)word1);
    list_enqueue(llist, (char*)word2);
    list_enqueue(llist, (char*)word3);
    list_enqueue(llist, (char*)word4);
    list_enqueue(llist, (char*)word5);
    list_enqueue(llist, (char*)word6);
    list_enqueue(llist, (char*)word7);
    list_enqueue(llist, (char*)word8);

    printf("\nPRINTING FULL LIST...");
    print_char_list(llist);

    char_list_remove(llist, (char*)word4);

    printf("\nPRINTING FULL LIST AFTER REMOVING davidson...");
    print_char_list(llist);

    void * removed_string = NULL;
    removed_string = list_get_nth_item(llist, 4);
    printf("THE 5ND ITEM  IN THE LIST IS %s\n", (char*)removed_string);


    list_dequeue(llist);

    printf("\nPRINTING FULL LIST AFTER DEQUEUE...");
    print_char_list(llist);


    list_destroy(llist);
    goto SUCCESS;


ERROR:
    exit(EXIT_FAILURE);

SUCCESS:
    exit(EXIT_SUCCESS);
}