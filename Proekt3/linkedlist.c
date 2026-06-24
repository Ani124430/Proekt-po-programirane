#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

LinkedList init() {
    LinkedList swimming = {
        .head = NULL,
        .size = 0
    };
    return swimming;
}

void pop(LinkedList *list, uint index) {
    if(index>= list->size) {
        printf("Index out of bounds!\n");
        exit(1);
    }
    if(index == 0) {
        Node * a = list->head;
        list->head = list->head->next;
        free(a);
        list->size--;
    }
    if(index>0) {
        Node *current = list->head;
        for(int i=0; i<index-1; i++) {
            current = current->next; 
        }
        Node *toDelete = current->next; 
        current->next= toDelete->next;
        free(toDelete); 
        list->size--;
    }
}

void pushBack(LinkedList *list, SwimmingStyle *value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value= *value;
    if(list->head == NULL) {
       list->head=newNode;
    }else{
        Node *current = list->head;
        for(int i = 0; i<list->size-1; i++){
            current = current->next;
        }
        current->next=newNode;
    }
    list->size++;
}

void freeList(LinkedList *list) {
    Node *current= list->head;
    while(current !=NULL) {
    Node *temp = current->next;
    free(current);
    current = temp;
    }
}