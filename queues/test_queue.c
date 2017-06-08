#include "queue.h"

int main (int argc, char * argv[]) {

    struct q_rep * q = malloc(sizeof(struct q_rep));
    q->head = NULL;
    q->tail = NULL;

    // Write some tests! See if you can cover every possible case
    // WITHOUT looking at the implementation of the functions declared
    // in queue.h
    //
    // Try and test my implementation - see if it is a working 
    // implementation... try and find a bug!

    for (int i = 0; i < 42; i++) {
        enqueue(q, i);
    }

    printQueue(q);
    queue_free(q);
    printQueue(q);

    for (int i = 0; i < 42; i++) {
        enqueue(q, i);
    }

    printQueue(q);
    queue_rfree(q);
    printQueue(q);

    return EXIT_SUCCESS;
}
