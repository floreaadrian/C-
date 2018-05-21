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
    : title(""), presenter(""), duration(Duration()), likes(), source("") {}

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

void Tutorial::tests() {
  this->titleTest();
  this->presenterTest();
  this->durationTest();
  this->sourceTest();
  this->likeTest();
  this->upLikeTest();
  this->equalTest();
}
void Tutorial::titleTest() {
  Tutorial test{"a", "b", Duration{10, 10}, 0, "http://"};
  assert(test.getTitle() == "b");
  Tutorial test1{"a", "c", Duration{10, 10}, 0, "http://"};
  assert(test1.getTitle() != "b");
}
void Tutorial::presenterTest() {
  Tutorial test{"a", "b", Duration{10, 10}, 0, "http://"};
  assert(test.getPresenter() == "a");
  Tutorial test1{"a", "c", Duration{10, 10}, 0, "http://"};
  assert(test1.getPresenter() != "b");
}
void Tutorial::durationTest() {
  Tutorial test{"a", "b", Duration{10, 10}, 0, "http://"};
  assert(test.getDuration().getMinutes() == 10 &&
         test.getDuration().getSeconds() == 10);
  Tutorial test1{"a", "b", Duration{23.32, 32.2}, 0, "http://"};
  assert(test1.getDuration().getMinutes() == 23.32 &&
         test1.getDuration().getSeconds() == 32.2);
  assert((test1.getDuration().getMinutes() == 0 &&
          test1.getDuration().getSeconds() == 10) == false);
}
void Tutorial::sourceTest() {
  Tutorial test{"a", "b", Duration{10, 10}, 0, "http://"};
  assert(test.getSource() == "http://");
  Tutorial test1{"a", "b", Duration{10, 10}, 0, "https://"};
  assert(test1.getSource() == "https://");
  assert(test1.getSource() != "http://");
}
void Tutorial::likeTest() {
  Tutorial test{"a", "b", Duration{10, 10}, 0, "http://"};
  assert(test.getLikes() == 0);
  Tutorial test1{"a", "b", Duration{10, 10}, 10, "http://"};
  assert(test1.getLikes() == 10);
}
void Tutorial::upLikeTest() {
  Tutorial test{"a", "b", Duration{10, 10}, 0, "http://"};
  assert(test.getLikes() == 0);
  Tutorial test1{"a", "b", Duration{10, 10}, 7, "http://"};
  test1.upLike();
  assert(test1.getLikes() == 8);
}
void Tutorial::equalTest() {
  Tutorial test{"a", "b", Duration{10, 10}, 0, "http://"};
  Tutorial test1{"a", "b", Duration{10, 10}, 7, "http://"};
  Tutorial test2{"v", "b", Duration{10, 10}, 7, "http://"};
  assert((test == test1) == true);
  assert((test == test2) == false);
}
