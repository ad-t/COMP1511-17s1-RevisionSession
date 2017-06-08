#include "linked_list.h"

struct node * createNode(int data) {
    struct node * newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("newNode is NULL!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct node * list, int data) {
    if (list == NULL) {
        return;
    }
    struct node * curr = list;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    struct node * newNode = createNode(data);
    if (newNode == NULL) {
        free(newNode);
        return;
    }
    curr->next = newNode;
}

int listSize(struct node * list) {
    if (list == NULL) {
        return 0;
    }
    int size = 0;
    struct node * curr = list;
    while (curr != NULL) {
        size++;
        curr = curr->next;
    }
    return size;
}

struct node * listRemove(struct node * list, int data) {
    if (list == NULL) {
        return NULL;
    } else if (list->next == NULL) {
        if (list->data == data) {
            free(list);
            return NULL;
        } else {
            return list;
        }
    } else {
        struct node * curr = list->next;
        struct node * prev = list;
        if (prev->data == data) {
            free(prev);
            return curr;
        }
        while (prev->next != NULL) {
            if (curr->data == data) {
                prev->next = curr->next;
                free(curr);
                return list;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return list;
}

int listMember(struct node * list, int data) {
    if (list == NULL) {
        return FALSE;
    }
    struct node * curr = list;
    while (curr != NULL) {
        if (curr->data == data) {
            return TRUE;
        }
        curr = curr->next;
    }
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
