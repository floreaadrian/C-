//
//  UI.h
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef UI_h
#define UI_h
#include "Controller.h"

class UI {
private:
  Controller ctrl;

public:
  UI(const Controller &c) : ctrl(c) {}

  void run();

private:
  static void printMenu();
  static void printRepositoryMenu();
  static void printWatchListMenu();

  void addTutorialToRepo();
  void deleteTutorial(int option);
  void updateTutorialToRepo();
  void displayAllTutorials(int option);
  void addTutorialToWatchlist();
  void addAllTutorialsByPresentersToWatchlist();
};

#endif /* UI_h */
