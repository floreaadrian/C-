//
//  DynamicArray.h
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef DynamicArray_h
#define DynamicArray_h

#include "Tutorial.h"

typedef Tutorial TElement;

class DynamicArray {
private:
  TElement *elems;
  int size;
  int capacity;

public:
  // default constructor for a DynamicArray
  DynamicArray(int capacity = 10);

  // copy constructor for a DynamicArray
  DynamicArray(const DynamicArray &v);
  ~DynamicArray();

  // assignment operator for a DynamicArray
  DynamicArray &operator=(const DynamicArray &v);
  DynamicArray &operator-(const TElement &e);
  friend bool operator==(const DynamicArray &a, const DynamicArray &b);

  // Adds an element to the current DynamicArray.
  void add(const TElement &e);
  void deleteElement(int pos);
  int getSize() const;
  TElement findByPresenterAndTitle(const std::string &presenter,
                                   const std::string &title);
  int findByPresenterAndTitlePos(const std::string &presenter,
                                 const std::string &title);

  TElement *getAllElems() const;

private:
  // Resizes the current DynamicArray, multiplying its capacity by a given
  // factor (real number).
  void resize(double factor = 2);
};

#endif /* DynamicArray_h */
