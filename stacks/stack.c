#include "stack.h"

struct node * createNode(int data) {
    struct node * new = malloc(sizeof(struct node));
    if (new == NULL) {
        return NULL;
    } 
    new->data = data;
    new->next = NULL;
    return new;
}

struct node * stackPush(struct s_rep * stack, int data) {
    if (stack == NULL) {
        return NULL;
    }
}

struct node * stackPop(struct s_rep * stack) {
    if (stack == NULL) {
        return NULL;
    } else if (stack->head == NULL || stack->tail == NULL) {
        return NULL;
    } else {
        struct node * top = stack->head;
        struct node * new_head = stack->head->next;
        stack->head = new_head;
        return top;
    }
}

int stackTop(struct s_rep * stack) {
    // TODO
    return 0;
}

int stackSize(struct s_rep * stack) {
    // TODO
    return 0;
}

int is_empty(struct s_rep * stack) {
    if (stack == NULL) {
        return TRUE; // 1
    } 
    return FALSE;
}
void free_stack(struct s_rep * stack);
void free_stackR(struct s_rep * stack);
