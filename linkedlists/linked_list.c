#include "linked_list.h"

struct node * createNode(int data) {
    // TODO
    return NULL;
}

void append(struct node * list, int data) {
    // TODO
}

int listSize(struct node * list) {
    // TODO
    return -1;
}

int listRemove(struct node * list, int data) {
    // TODO
    return -1;
}

int listMember(struct node * list, int data) {
    // TODO
    return FALSE;
}   

void printList(struct node * list) {
    if (list == NULL) {
        printf("(empty list)\n");
        return;
    }
    struct node * curr = list;
    printf("[");
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(", ");
        }
        curr = curr->next;
    }
    printf("]\n");
}
