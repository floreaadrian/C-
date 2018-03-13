#pragma once
#include "../domain/domain.h"
#include <stdlib.h>

typedef Country Element;

typedef struct {
  Element *elems;
  int length; // actual length of the array
  int capacity;
} Repo;

Repo *createRepo(int capacity);
void addInArray(Repo *arr, Element t);
void freeRepo(Repo *arr);
void freeRepo(Repo *r);
TElement get(Repo *arr, int pos);
int getLength(Repo *arr);
void delete (Repo *arr, int pos);
