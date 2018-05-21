//
//  Filter.hpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 4/5/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//
#pragma once
#include "Tutorial.h"
#include <string>

template <typename T> class Comparator {
public:
  virtual bool include(const T &a, const T &b) const = 0;
  virtual ~Comparator(){};
};

class FilterLessMinutes : public Comparator<Tutorial> {
public:
  bool include(const Tutorial &a, const Tutorial &b) const {
    return a.getDuration().getMinutes() < b.getDuration().getMinutes();
  }
};
class FilterMoreMinutes : public Comparator<Tutorial> {

public:
  bool include(const Tutorial &a, const Tutorial &b) const {
    std::cout << a.getDuration().getMinutes() << " ";
    return a.getDuration().getMinutes() >= b.getDuration().getMinutes();
  }
};

class FilterTitleBigger : public Comparator<Tutorial> {
public:
  bool include(const Tutorial &a, const Tutorial &b) const {
    return a.getTitle() > b.getTitle();
  }
};
