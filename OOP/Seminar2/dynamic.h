#pragma once

typedef int TElement;

class DynamicArray {
private:
  int capacity;
  int size;
  TElement *elems;

public:
  DynamicArray(int cap = 10);
  DynamicArray(const DynamicArray &arr);
  DynamicArray(const DynamicArray &arr);
  ~DynamicArray();
};
