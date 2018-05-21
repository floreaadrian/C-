//
//  DynamicArray.h
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef DynamicArray_h
#define DynamicArray_h

#include "Filter.h"
#include "Tutorial.h"

template <typename TElement> class DynamicArray {
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
  TElement operator[](int pos) const;
  // friend bool operator==(const DynamicArray &a, const DynamicArray &b);

  // Adds an element to the current DynamicArray.
  void add(const TElement &e);
  void deleteElement(int pos);
  int getSize() const;
  TElement findByPresenterAndTitle(const std::string &presenter,
                                   const std::string &title);
  int findByPresenterAndTitlePos(const std::string &presenter,
                                 const std::string &title);

  TElement *getAllElems() const;
  DynamicArray filterBy(const DynamicArray &v,
                        const Comparator<Tutorial> &filter);
  void tests();
  void addTest();
  void deleteTest();
  void getSizeTest();
  void findByTest();
  void findByElementTest();
  void assigmentTest();
  void equalTest();
  void sortTest();

private:
  // Resizes the current DynamicArray, multiplying its capacity by a given
  // factor (real number).
  void resize(double factor = 2);
};
template <typename TElement>
DynamicArray<TElement>::DynamicArray(int capacity) {
  this->size = 0;
  this->capacity = capacity;
  this->elems = new TElement[capacity];
}
template <typename TElement>
DynamicArray<TElement>::DynamicArray(const DynamicArray &v) {
  this->size = v.size;
  this->capacity = v.capacity;
  this->elems = new TElement[this->capacity];
  for (int i = 0; i < this->size; i++)
    this->elems[i] = v.elems[i];
}

template <typename TElement> DynamicArray<TElement>::~DynamicArray() {
  delete[] this->elems;
}
template <typename TElement>
DynamicArray<TElement> &DynamicArray<TElement>::
operator=(const DynamicArray<TElement> &v) {
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

template <typename TElement>
DynamicArray<TElement> &DynamicArray<TElement>::operator-(const TElement &e) {
  for (int i = 0; i < this->size; i++)
    if (this->elems[i] == e)
      deleteElement(i);
  return *this;
}

template <typename TElement>
TElement DynamicArray<TElement>::operator[](int pos) const {
  return this->elems[pos];
}
// template <typename TElement>
// bool operator==(const DynamicArray<TElement> &a,
//                 const DynamicArray<TElement> &b) {
//   if (a.getSize() != b.getSize())
//     return false;
//   for (int i = 0; i < a.getSize(); i++)
//     if (a.elems[i] == b.elems[i])
//       continue;
//     else
//       return false;
//   return true;
// }

template <typename TElement>
void DynamicArray<TElement>::add(const TElement &e) {
  if (this->size == this->capacity)
    this->resize();
  this->elems[this->size] = e;
  this->size++;
}

template <typename TElement>
void DynamicArray<TElement>::deleteElement(int pos) {
  if (pos != -1) {
    for (int i = pos; i < this->size - 1; i++)
      this->elems[i] = this->elems[i + 1];
    // we just got rid of a country
    this->size--;
  }
}

template <typename TElement>
void DynamicArray<TElement>::resize(double factor) {
  this->capacity *= static_cast<int>(factor);

  TElement *els = new TElement[this->capacity];
  for (int i = 0; i < this->size; i++)
    els[i] = this->elems[i];

  delete[] this->elems;
  this->elems = els;
}
template <typename TElement>
TElement *DynamicArray<TElement>::getAllElems() const {
  return this->elems;
}

template <typename TElement>
TElement
DynamicArray<TElement>::findByPresenterAndTitle(const std::string &presenter,
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

template <typename TElement>
int DynamicArray<TElement>::findByPresenterAndTitlePos(
    const std::string &presenter, const std::string &title) {
  if (this->size == 0)
    return -1;
  for (int i = 0; i < this->size; i++) {
    Tutorial s = this->elems[i];
    if (s.getPresenter() == presenter && s.getTitle() == title)
      return i;
  }

  return -1;
}

template <typename TElement>
DynamicArray<TElement>
DynamicArray<TElement>::filterBy(const DynamicArray<TElement> &v,
                                 const Comparator<Tutorial> &filter) {
  TElement aux;
    for(int j= 0 ;j<this->size;++j)
  for (int i = 0; i < this->size; ++i) {
    if (filter.include(v.elems[i], v.elems[j])) {
      aux = v.elems[i];
      v.elems[i] = v.elems[j];
      v.elems[j] = aux;
    }
  }
  return v;
}

template <typename TElement> int DynamicArray<TElement>::getSize() const {
  return this->size;
}

template <typename TElement> void DynamicArray<TElement>::tests() {
  this->addTest();
  this->deleteTest();
  this->getSizeTest();
  this->findByTest();
  this->findByElementTest();
  this->sortTest();
  // this->assigmentTest();
  // this->equalTest();
}

template <typename TElement> void DynamicArray<TElement>::addTest() {
  DynamicArray<TElement> test;
  TElement t{"a", "b", Duration{10, 10}, 0, "http://"};
  test.add(t);
  assert(test.findByPresenterAndTitlePos("a", "b") != -1);
}
template <typename TElement> void DynamicArray<TElement>::deleteTest() {
  DynamicArray<TElement> test;
  TElement t{"a", "b", Duration{10, 10}, 0, "http://"};
  test.add(t);
  test.deleteElement(0);
  assert(test.findByPresenterAndTitlePos("a", "b") == -1);
}
template <typename TElement> void DynamicArray<TElement>::getSizeTest() {
  DynamicArray<TElement> test;
  TElement t{"a", "b", Duration{10, 10}, 0, "http://"};
  test.add(t);
  TElement t1{"b", "b", Duration{10, 10}, 0, "http://"};
  test.add(t1);
  TElement t2{"c", "b", Duration{10, 10}, 0, "http://"};
  test.add(t2);
  assert(test.getSize() == 3);
}
template <typename TElement> void DynamicArray<TElement>::findByTest() {
  DynamicArray<TElement> test;
  TElement t{"a", "b", Duration{10, 10}, 0, "http://"};
  test.add(t);
  TElement t1{"b", "b", Duration{10, 10}, 0, "http://"};
  test.add(t1);
  assert(test.findByPresenterAndTitlePos("b", "b") == 1);
}
template <typename TElement> void DynamicArray<TElement>::findByElementTest() {
  DynamicArray<TElement> test;
  TElement t{"a", "b", Duration{10, 10}, 0, "http://"};
  test.add(t);
  assert(test.findByPresenterAndTitle("a", "b") == t);
}

template <typename TElement> void DynamicArray<TElement>::sortTest() {
  DynamicArray<TElement> test;
  TElement t{"a", "b", Duration{10, 10}, 0, "http://"};
  test.add(t);
  TElement t1{"b", "b", Duration{2, 10}, 0, "http://"};
  test.add(t1);
  TElement t2{"c", "b", Duration{1, 10}, 0, "http://"};
  test.add(t2);
  FilterTitleBigger filterMore{};
  test = test.filterBy(test, filterMore);
  assert(test.findByPresenterAndTitlePos("b", "b") == 1);
  assert(test.findByPresenterAndTitlePos("c", "b") == 2);
}

// template <typename TElement> void DynamicArray<TElement>::equalTest() {
//   DynamicArray<TElement> test;
//   DynamicArray<TElement> test1;
//   TElement t{"a", "b", Duration{10, 10}, 0, "http://"};
//   test.add(t);
//   test1.add(t);
//   TElement t1{"a", "b", Duration{10, 10}, 0, "http://"};
//   test.add(t1);
//   test1.add(t1);
//   assert((test1 == test) == true);
//   test.deleteElement(1);
//   assert((test1 == test) == false);
// }
//
// template <typename TElement> void DynamicArray<TElement>::assigmentTest() {
//   DynamicArray<TElement> test;
//   DynamicArray<TElement> test1;
//   TElement t{"a", "b", Duration{10, 10}, 0, "http://"};
//   test.add(t);
//   TElement t1{"a", "b", Duration{10, 10}, 0, "http://"};
//   test.add(t1);
//   test1 = test;
//   assert(test1 == test);
// }

#endif /* DynamicArray_h */
