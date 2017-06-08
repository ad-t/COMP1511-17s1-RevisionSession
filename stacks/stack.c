#include "stack.h"

struct node * createNode(int data) {
    // TODO
    return NULL;
}

void stackPush(struct node * stack, int data) {
    // TODO
}

struct node * stackPop(struct node * stack) {
    if (stack == NULL) {
        return NULL;
    } else if (stack->next == NULL) {
        return stack;
    } else {
        struct node * new_head = stack->next;
        stack->next = NULL;
        return stack;
    }
}

int stackTop(struct node * stack) {
    // TODO
    return 0;
}

int stackSize(struct node * stack) {
    // TODO
    return 0;
}

int is_empty(struct node * stack) {
    if (stack == NULL) {
        return TRUE; // 1
    } 
    return FALSE;
}
void free_stack(struct node * stack);
void free_stackR(struct node * stack);
