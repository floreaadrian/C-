//
//  Tutorial.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Tutorial.h"
#include <cstdlib>
#include <iostream>
#include <string.h>

Tutorial::Tutorial()
    : title(""), presenter(""), duration(Duration()), source("") {}

Tutorial::Tutorial(const std::string &presenter, const std::string &title,
                   const Duration &duration, const int &likes,
                   const std::string &source) {
  this->presenter = presenter;
  this->title = title;
  this->duration = duration;
  this->likes = likes;
  this->source = source;
}

bool operator==(const Tutorial &a, const Tutorial &b) {
  if (a.getTitle() == b.getTitle() && a.getPresenter() == b.getPresenter())
    return true;
  return false;
}

void Tutorial::upLike() { this->likes++; }

void Tutorial::play() {
  std::string link = "open -a Safari " + this->getSource();
  std::system(link.c_str());
}
