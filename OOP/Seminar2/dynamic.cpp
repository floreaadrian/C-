#include "dynamic.h"

DynamicArray::DynamicArray(int cap) {
  this->capacity = cap;
  this->size = 0;
  this->elems = new TElement[this->capacity];
}
DynamicArray::~DynamicArray() { delete[] this->elems; }

DynamicArray &DynamicArray::operator=(const DynamicArray &arr) {
  if (this == &arr)
    return *this;

  delete[] this->elems;
  this->elems = new TElement[this->capacity];
  this->capacity = arr.capacity;
  this->size = arr.size;
  for (int i = 0; i < arr.size; ++i) {
    this->elems[i] = arr.elems[i];
  }
  return *this;
}

DynamicArray::DynamicArray(const DynamicArray &arr) {
  this->capacity = arr.capacity;
  this->size = arr.size;
  this->elems = new TElement[this->capacity];
  for (int i = 0; i < this->size; i++) {
    this->elems[i] = arr.elems[i];
  }
}
