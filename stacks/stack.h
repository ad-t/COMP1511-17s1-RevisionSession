#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node * next;
};

struct node * createNode(int data);
struct node * stackPush(struct node * stack, int data);
struct node * stackPop(struct node * stack);

int stackTop(struct node * stack);
int stackSize(struct node * stack);
int is_empty(struct node * stack);

void free_stack(struct node * stack);
void free_stackR(struct node * stack);

#endif
