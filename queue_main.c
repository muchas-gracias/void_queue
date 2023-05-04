#include "queue.h"

int main()
{
    int return_flag = 1;
    // inserting ints
    int num0 = 10;
    int num1 = 55;
    int num2 = 87;

    queue_t * queue = queue_create();
    if (NULL == queue)
    {
        goto EXIT;
    }
    // enqueuing each number
    queue_enqueue(queue, &num0);
    queue_enqueue(queue, &num1);
    queue_enqueue(queue, &num2);

    fprintf(stdout, "PRINTING FULL LIST...=>");
    print_integer_queue(queue);

    int   sampl  = 807;
    int * result = NULL;

    // getting the nth item in the queue
    result = queue_get_nth_item(queue, 2);
    if (NULL != result)
    {
        fprintf(stdout, "THE 3RD ITEM IN THE LIST IS...=> %d\n", *result);
    }
    else
    {
        fprintf(stdout, "Unable to retrieve the value...not in the queue\n");
    }

    if (true == queue_contains(queue, &sampl))
    {
        fprintf(stdout, "\n%d IS IN THE LIST\n", sampl);
    }
    else
    {
        fprintf(stdout, "\n%d IS NOT IN THE LIST\n", sampl);
    }

    // removing and item from the queue
    int val_to_remove = 87;
    if (1 == int_queue_remove(queue, &val_to_remove))
    {
        fprintf(stdout, "\nUnable to remove value...not in the queue\n");
    }

    fprintf(stdout, "\nPRINTING FULL LIST...=>");
    print_integer_queue(queue);

    remove_all(queue);

    queue_destroy(queue);
    queue = NULL;

    // inserting strings
    queue_t * re_queue = queue_create();
    if (NULL == re_queue)
    {
        goto EXIT;
    }
    const char * word  = "brent";
    const char * word1 = "davis";
    const char * word2 = "smith";
    const char * word3 = "bill";
    const char * word4 = "davidson";
    const char * word5 = "harley";
    const char * word6 = "bilal";
    const char * word7 = "dirk";
    const char * word8 = "sammy";

    queue_enqueue(re_queue, (char *)word);
    queue_enqueue(re_queue, (char *)word1);
    queue_enqueue(re_queue, (char *)word2);
    queue_enqueue(re_queue, (char *)word3);
    queue_enqueue(re_queue, (char *)word4);
    queue_enqueue(re_queue, (char *)word5);
    queue_enqueue(re_queue, (char *)word6);
    queue_enqueue(re_queue, (char *)word7);
    queue_enqueue(re_queue, (char *)word8);

    fprintf(stdout, "\nPRINTING FULL LIST...=>");
    print_char_queue(re_queue);

    if (1 == char_queue_remove(re_queue, (char *)word4))
    {
        fprintf(stdout, "Unable to remove value...not in the queue\n");
    }

    fprintf(stdout, "\nPRINTING FULL LIST AFTER REMOVING davidson...");
    print_char_queue(re_queue);

    void * removed_string = NULL;
    removed_string        = queue_get_nth_item(re_queue, 4);

    if (NULL != removed_string)
    {
        fprintf(stdout, "\nRemoved value:THE 5TH ITEM IN THE LIST IS==> ");
        fprintf(stdout, "%s\n", (char *)removed_string);
    }
    else
    {
        fprintf(stdout, "\nUnable to retrieve the value...not in the queue\n");
    }

    queue_dequeue(re_queue);

    fprintf(stdout, "\nPRINTING FULL LIST AFTER DEQUEUE...=>");
    print_char_queue(re_queue);

    remove_all(re_queue);

    if (1 == queue_destroy(re_queue))
    {
        fprintf(stdout, "Unable to destroy the queue\n");
    }
    re_queue    = NULL;
    return_flag = 0;

EXIT:
    return return_flag == 0 ? 0 : 1;
}