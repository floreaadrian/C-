//
//  Watchlist.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 4/3/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Filter.h"
#include "Watchlist.h"
Watchlist::Watchlist() { this->current = 0; }

void Watchlist::add(const Tutorial &song) { this->Tutorials.add(song); }

int Watchlist::deleteTutorial(const Tutorial &e) {
  this->Tutorials = this->Tutorials - e;
  return 1;
}

Tutorial Watchlist::getCurrentTutorial() {
  if (this->current == this->Tutorials.getSize())
    this->current = 0;
  Tutorial *elems = this->Tutorials.getAllElems();
  if (elems != NULL)
    return elems[this->current];
  return Tutorial{};
}

int Watchlist::deleteTutorialWatchlistNameAndPresenter(
    const std::string &presenter, const std::string &title) {
  if (this->Tutorials.findByPresenterAndTitlePos(presenter, title) != -1) {
    this->Tutorials = this->Tutorials -
                      this->Tutorials.findByPresenterAndTitle(presenter, title);
    return 1;
  }
  return 0;
}

void Watchlist::play() {
  if (this->Tutorials.getSize() == 0)
    return;
  Tutorial currentTutorial = this->getCurrentTutorial();
  currentTutorial.play();
}

void Watchlist::next() {
  if (this->Tutorials.getSize() == 0)
    return;
  this->current = (this->current + 1) % this->Tutorials.getSize();
  Tutorial currentTutorial = this->getCurrentTutorial();
  currentTutorial.play();
}

DynamicArray<Tutorial> Watchlist::sort() {
  FilterMoreMinutes filterMore{};
  return this->Tutorials.filterBy(this->getTutorials(), filterMore);
}

bool Watchlist::isEmpty() { return this->Tutorials.getSize() == 0; }

// tests

void Watchlist::tests() {
  this->addTest();
  this->deleteElemTest();
  this->getCurrentTest();
  this->getCurrentNumberTest();
  this->deleteTest();
  this->playTest();
  this->nextTest();
  this->emptyTest();
}
void Watchlist::addTest() {
  Watchlist watch;
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  assert(watch.getTutorials().getSize() == 2);
}

void Watchlist::deleteElemTest() {
  Watchlist watch;
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  watch.deleteTutorial(s1);
  assert(watch.getTutorials().getSize() == 1);
  watch.deleteTutorial(s2);
  assert(watch.getTutorials().getSize() == 0);
}
void Watchlist::getCurrentTest() {
  Watchlist watch;
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  assert(watch.getCurrentTutorial() == s1);
  watch.deleteTutorial(s1);
  assert(watch.getCurrentTutorial() == s2);
}
void Watchlist::getCurrentNumberTest() {
  Watchlist watch;
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  assert(watch.getCurrentNumber() == 0);
  watch.next();
  assert(watch.getCurrentNumber() == 1);
}
void Watchlist::deleteTest() {
  Watchlist watch;
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  assert(watch.deleteTutorialWatchlistNameAndPresenter("a", "b") == 1);
  assert(watch.getTutorials().getSize() == 1);
  assert(watch.getTutorials().findByPresenterAndTitlePos("a", "b") == -1);
}
void Watchlist::playTest() {
  Watchlist watch;
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.play();
  assert(watch.getCurrentNumber() == 0);
}
void Watchlist::nextTest() {
  Watchlist watch;
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  watch.next();
  assert(watch.getCurrentNumber() == 1);
  watch.next();
  assert(watch.getCurrentNumber() == 0);
}
void Watchlist::emptyTest() {
  Watchlist watch;
  assert(watch.isEmpty() == true);
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  assert(watch.isEmpty() == false);
  watch.deleteTutorial(s1);
  watch.deleteTutorial(s2);
  assert(watch.isEmpty() == true);
}
