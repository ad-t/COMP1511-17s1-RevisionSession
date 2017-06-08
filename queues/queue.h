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

struct q_rep {
    struct node * head;
    struct node * tail;
};

struct node * createNode(int data);
struct node * enqueue(struct q_rep * queue, int data);
int dequeue(struct q_rep * queue);
int queue_is_empty(struct q_rep * queue);
int queue_front(struct q_rep * queue);
int queue_size(struct q_rep * queue);

void queue_free(struct q_rep * queue);
void queue_rfree(struct q_rep * queue);

void printQueue(struct q_rep * queue);

#endif
