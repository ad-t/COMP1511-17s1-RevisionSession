#include "stack.h"

int main (int argc, char * argv[]) {

    struct s_rep * s = malloc(sizeof(struct s_rep));
    s->head = NULL;
    s->tail = NULL;

    // Write some tests! See if you can cover every possible case
    // WITHOUT looking at the implementation of the functions declared
    // in stack.h
    //
    // Try and test my implementation - see if it is a working 
    // implementation... try and find a bug!
    
    for (int i = 0; i < 32; i++) {
        stackPush(s, i);
    }

    printStack(s);
    free_stack(s);
    printStack(s);
    
    for (int i = 0; i < 32; i++) {
        stackPush(s, i);
    }

    printStack(s);
    free_stack(s);
    printStack(s);

    free(s);

    return EXIT_SUCCESS;
}
