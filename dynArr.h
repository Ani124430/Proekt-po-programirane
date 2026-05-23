#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
 
typedef unsigned int uint;
typedef int DynArrType;
 
typedef struct {
  uint size;
  uint capacity;
  DynArrType* buffer;
} DynamicArray;
 
DynamicArray init(uint capacity);
 
void      pushBack (DynamicArray* dynArr, DynArrType value);
void      pushFront(DynamicArray* dynArr, DynArrType value);
void      push     (DynamicArray* dynArr, uint index, DynArrType value);
 
DynArrType popBack (DynamicArray* dynArr);
DynArrType popFront(DynamicArray* dynArr);
DynArrType pop     (DynamicArray* dynArr, uint index);
 
DynArrType get(DynamicArray* dynArr, uint index);
void       set(DynamicArray* dynArr, uint index, DynArrType value);
 
// Връща индекса на първия намерен елемент или -1
int findIndex(DynamicArray* dynArr, DynArrType value);
 
void release(DynamicArray* dynArr);
 
#endif // DYNAMIC_ARRAY_H
 