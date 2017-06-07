#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node * next;
};

struct node * createNode(int data);
struct node * enqueue(struct node * queue, int data);
int dequeue(struct node * queue);
int queue_is_empty(struct node * queue);
int queue_front(struct node * queue);
int queue_size(struct node * queue);

void queue_free(struct node * queue);
void queue_rfree(struct node * queue);

#endif
