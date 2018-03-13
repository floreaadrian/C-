#pragma once
#include "../domain/domain.h"

typedef Country *Element; // a more generic name for an array elements

typedef struct {
  Element *elems;
  int length;   // actual length of the array
  int capacity; // maximum capacity of the array
} Arrays;

Arrays *createArrays(int capacity); // creating array
void destroy(Arrays *arr);          // destroing array

void addToArray(Arrays *arr, Element t); // adding an element to the array
void delete (Arrays *arr, int pos);      // deleting an element from the array

int getLength(Arrays *arr); // getting the lenght of a certain array
Element getCountry(Arrays *arr,
                   int pos); // getting an element from a position in a array
