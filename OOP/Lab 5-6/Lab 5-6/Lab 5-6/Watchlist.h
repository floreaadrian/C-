//
//  Watchlist.h
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 4/3/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Watchlist_h
#define Watchlist_h

#pragma once
#include "DynamicArray.h"

class Watchlist {
private:
  DynamicArray<Tutorial> Tutorials;
  int current;

public:
  Watchlist();

  // Adds a tutorial to the playlist.
  void add(const Tutorial &tutorial);
  int deleteTutorial(const Tutorial &e);
  // Returns the tutorial that is currently playing.
  Tutorial getCurrentTutorial();
  int getCurrentNumber() { return this->current; }

  DynamicArray<Tutorial> getTutorials() const { return Tutorials; }
  int deleteTutorialWatchlistNameAndPresenter(const std::string &presenter,
                                              const std::string &title);
  // Starts the playlist - plays the first tutorial.
  void play();

  // Plays the next tutorial in the playlist.
  void next();
  DynamicArray<Tutorial> sort();
  // Checks if the playlist is empty.
  bool isEmpty();
  // tests
  void tests();
  void addTest();
  void deleteElemTest();
  void getCurrentTest();
  void getCurrentNumberTest();
  void deleteTest();
  void playTest();
  void nextTest();
  void emptyTest();
};

#endif /* Watchlist_h */
