//
//  Watchlist.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 4/3/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

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

bool Watchlist::isEmpty() { return this->Tutorials.getSize() == 0; }
