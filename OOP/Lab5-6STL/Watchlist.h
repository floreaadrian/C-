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
#include <vector>
#include "Tutorial.h"
class Watchlist {
protected:
  std::vector<Tutorial> Tutorials;
  std::vector<Tutorial> TutorialInWatch;
  int current;
  int currentIn;
  std::string filename;

public:
  Watchlist();

  // Adds a tutorial to the playlist.
  void add(const Tutorial &tutorial);
  void addWatch();
  int deleteTutorial(const Tutorial &e);
  // Returns the tutorial that is currently playing.
  Tutorial getCurrentTutorial(int option);
  int getCurrentNumber() { return this->current; }
  int getCurrentNumberIn() { return this->currentIn; }

  std::vector<Tutorial> getTutorials() const { return this->Tutorials; }
  std::vector<Tutorial> getWatch() const { return this->TutorialInWatch; }
  int deleteTutorialWatchlistNameAndPresenter(const std::string &presenter,
                                              const std::string &title);
  // Starts the playlist - plays the first tutorial.
  void play(int option);
  Tutorial findByPresenterAndTitle(const std::string &presenter,
                                   const std::string &title);
  int findByPresenterAndTitlePos(const std::string &presenter,
                                 const std::string &title);
  // Plays the next tutorial in the playlist.
  void next(int option);
  std::vector<Tutorial> sorted();
  void writeToFile();
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
  void sortTest();
  virtual ~Watchlist() {}
};

#endif /* Watchlist_h */
