#include "queue.h"

struct node * createNode(int data) {
    struct node * newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node * enqueue(struct q_rep * queue, int data) {
    if (queue == NULL) {
        return NULL;
    } else if (queue->head == NULL || queue->tail == NULL) {
        struct node * newNode = createNode(data);
        queue->head = newNode;
        queue->tail = newNode;
        return newNode;
    } else {
        struct node * newNode = createNode(data);
        queue->tail->next = newNode;
        queue->tail = newNode;
        return newNode;
    }
    return NULL;
}

int dequeue(struct q_rep * queue) {
    if (queue == NULL) {
        return 0;
    } else if (queue->head == NULL || queue->tail == NULL) {
        return 0;
    } else {
        struct node * remove = queue->head;
        queue->head = remove->next;
        return 1;
    }
    return 0;
}

int queue_is_empty(struct q_rep * queue) {
    if (queue == NULL) {
        return TRUE;
    } else {
        if (queue->head == NULL || queue->tail == NULL) {
            return TRUE;
        } else {
            return FALSE;
        }
    }
    return TRUE;
}

int queue_front(struct q_rep * queue) {
    if (queue == NULL) {
        return 0;
    } else {
        if (queue_is_empty(queue)) {
            return 0;
        } else {
            return queue->head->data;
        }
    }
    return 0;
}

int queue_size(struct q_rep * queue) {
    if (queue == NULL) {
        return 0;
    } else {
        struct node * curr = queue->head;
        int size = 0;
        while (curr != NULL) {
            size++;
            curr = curr->next;
        }
        return size;
    }
    return 0;
}

void queue_free(struct q_rep * queue) {
    if (queue == NULL) {
        return;
    } else {
        if (queue_is_empty(queue)) {
            return;
        } else {
            struct node * curr = queue->head;
            struct node * following = NULL;
            while (curr != NULL) {
                if (following == NULL) {
                    following = curr->next;
                }
                free(curr);
                curr = following;
                following = following->next;
            }
        }
    }
    return;
}

void queue_rfree_worker(struct node * head) {
    if (head == NULL) {
        return;
    } else {
        queue_rfree_worker(head->next);
        free(head);
    }
}

void queue_rfree(struct q_rep * queue) {
    if (queue == NULL) {
        return;
    } else {
        queue_rfree_worker(queue->head);
        queue->head = NULL;
        queue->tail = NULL;
    }
    return;
}
