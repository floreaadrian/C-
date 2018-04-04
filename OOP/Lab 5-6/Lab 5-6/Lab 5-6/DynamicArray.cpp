//
//  DynamicArray.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "DynamicArray.h"

DynamicArray::DynamicArray(int capacity) {
  this->size = 0;
  this->capacity = capacity;
  this->elems = new TElement[capacity];
}

DynamicArray::DynamicArray(const DynamicArray &v) {
  this->size = v.size;
  this->capacity = v.capacity;
  this->elems = new TElement[this->capacity];
  for (int i = 0; i < this->size; i++)
    this->elems[i] = v.elems[i];
}

DynamicArray::~DynamicArray() { delete[] this->elems; }

DynamicArray &DynamicArray::operator=(const DynamicArray &v) {
  if (this == &v)
    return *this;

  this->size = v.size;
  this->capacity = v.capacity;

  delete[] this->elems;
  this->elems = new TElement[this->capacity];
  for (int i = 0; i < this->size; i++)
    this->elems[i] = v.elems[i];

  return *this;
}

DynamicArray &DynamicArray::operator-(const TElement &e) {
  for (int i = 0; i < this->size; i++)
    if (this->elems[i] == e)
      deleteElement(i);
  return *this;
}

bool operator==(const DynamicArray &a, const DynamicArray &b) {
  if (a.getSize() != b.getSize())
    return false;
  for (int i = 0; i < a.getSize(); i++)
    if (a.elems[i] == b.elems[i])
        continue;
    else return false;
  return true;
}

void DynamicArray::add(const TElement &e) {
  if (this->size == this->capacity)
    this->resize();
  this->elems[this->size] = e;
  this->size++;
}

void DynamicArray::deleteElement(int pos) {
  if (pos != -1) {
    for (int i = pos; i < this->size - 1; i++)
      this->elems[i] = this->elems[i + 1];
    // we just got rid of a country
    this->size--;
  }
}

void DynamicArray::resize(double factor) {
  this->capacity *= static_cast<int>(factor);

  TElement *els = new TElement[this->capacity];
  for (int i = 0; i < this->size; i++)
    els[i] = this->elems[i];

  delete[] this->elems;
  this->elems = els;
}

TElement *DynamicArray::getAllElems() const { return this->elems; }

TElement DynamicArray::findByPresenterAndTitle(const std::string &presenter,
                                               const std::string &title) {
  if (this->size == 0)
    return TElement{};
  for (int i = 0; i < this->size; i++) {
    TElement s = this->elems[i];
    if (s.getPresenter() == presenter && s.getTitle() == title)
      return s;
  }

  return TElement{};
}

int DynamicArray::findByPresenterAndTitlePos(const std::string &presenter,
                                             const std::string &title) {
  if (this->size == 0)
    return -1;
  for (int i = 0; i < this->size; i++) {
    Tutorial s = this->elems[i];
    if (s.getPresenter() == presenter && s.getTitle() == title)
      return i;
  }

  return -1;
}

int DynamicArray::getSize() const { return this->size; }
