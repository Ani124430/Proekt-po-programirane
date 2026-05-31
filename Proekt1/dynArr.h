#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include "swimming.h"
 
typedef unsigned int uint;
 
typedef struct DynamicArray {
  uint size;
  uint capacity;
  SwimmingStyle* buffer;
} DynamicArray;
 
DynamicArray init(uint capacity);
 
void      pushBack (DynamicArray* dynArr, SwimmingStyle* value);
 
void pop     (DynamicArray* dynArr, uint index);
 
#endif 
 