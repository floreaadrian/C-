#pragma once
#include "../domain/domain.h"
#define CAPACITY 10

typedef Country *Element;

typedef struct {
  Element *elems;
  int length;   // actual length of the array
  int capacity; // maximum capacity of the array
} Arrays;

Arrays *createArrays(int capacity);
void destroy(Arrays *arr);
void addToArray(Arrays *arr, Element t);

void delete (Arrays *arr, int pos);

int getLength(Arrays *arr);

Element getCountry(Arrays *arr, int pos);
