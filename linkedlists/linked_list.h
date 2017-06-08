#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct node {
    int             data;
    struct node *   next;
};

struct node * createNode(int data);
void append(struct node * list, int data);
int listSize(struct node * list);
struct node * listRemove(struct node * list, int data);
int listMember(struct node * list, int data);
void printList(struct node * list);

// if we have time:
/*

int insertOrdered(struct node * list);
int is_ordered(struct node * list);
struct node * reverse(struct node * list);
struct node * copy(struct node * list);

 */

#endif
