#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "swimming.h"

typedef unsigned int uint;

typedef struct Node {
    SwimmingStyle value;
    struct Node * next;
}Node;

typedef struct {
    Node *head;
    int size;
}LinkedList;

LinkedList init();

void pushBack(LinkedList* list, SwimmingStyle* value);
void pop(LinkedList* list, uint index);
void freeaList(LinkedList *list);


#endif