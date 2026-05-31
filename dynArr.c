#include <stdio.h>
#include<stdlib.h> 
#include"dynArr.h"

DynamicArray init(uint capacity) {
    if (capacity < 0) {
    printf("Invalid capacity\n");
    exit(1);
  }
  DynamicArray Swimming = {
    .size = 0,
    .capacity = capacity,
    .buffer = NULL
  };

  if (Swimming.capacity > 0) {
    Swimming.buffer = calloc(Swimming.capacity, sizeof(SwimmingStyle));
    if (Swimming.buffer==NULL) {
        printf("Error");
        exit(1);
    }
  }

  return Swimming;
}

void pushBack(DynamicArray * dynArr, SwimmingStyle* value) {
    int newsize = dynArr->size+1;
    if(dynArr->size == dynArr->capacity){
        dynArr->buffer = realloc(dynArr->buffer, sizeof(SwimmingStyle) * newsize);
        if (dynArr->buffer == NULL) {
            printf("Error");
            exit(1);
        }
    }
    dynArr->buffer[newsize-1] = *value;
    dynArr->size++;
}

void pop(DynamicArray* dynArr, uint index) {
    uint newSize = dynArr->size - 1;
    SwimmingStyle result = dynArr->buffer[index];
    for (int i = index; i < newSize; i++) {
        dynArr->buffer[i] = dynArr->buffer[i+1];
    }
    dynArr->size--;
}


