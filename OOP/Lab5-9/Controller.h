//
//  Controller.h
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Controller_h
#define Controller_h

#include "Repo.h"
#include "TutorialValidator.h"
#include "FileWatchlist.h"
#include <vector>

class Controller
{
private:
  Repository repo;
  FileWatchlist *watchList;
  TutorialValidator validator;

public:
  Controller(const Repository &r, FileWatchlist *w, TutorialValidator v)
      : repo{r}, watchList{w}, validator{v} {}

  Repository getRepo() const { return repo; }
  Watchlist *getWatchlist() const { return watchList; }

  // Adds a Tutorial with the given data to the Tutorial repository.
  int addTutorialToRepository(const std::string &presenter,
                              const std::string &title, double minutes,
                              double seconds, int likes,
                              const std::string &source);
  int deleteTutorialToRepository(const std::string &presenter,
                                 const std::string &title);
  int updateTutorialToRepository(const std::string &presenter,
                                 const std::string &title,
                                 const std::string &newPresenter,
                                 const std::string &newTitle, double minutes,
                                 double seconds, int likes,
                                 const std::string &source);
  int deleteTutorialWatchlistNameAndPresenterCtrl(const std::string &presenter,
                                                  const std::string &title,
                                                  bool like);
  // Adds all the tutorialss from the repository, that have the given presenter,
  // to the current Watchlist.
  void addAllTutorialsByPresenterToWatchlist(const std::string &presenter);
  void addAllTutorialsToWatchlist();
  void addCurrentWatchlist();
  std::vector<Tutorial> sorted();
  int deleteTutorialWatchlist(const Tutorial &tutorial);
  void playWatchlist(int option);
  void write();
  /*
    Saves the Watchlist.
    Throws: FileException - if the given file cannot be opened.
    */
  void saveWatchlist();

  /*
    Opens the Watchlist, with an appropriate application.
    Throws: FileException - if the given file cannot be opened.
    */
  void openWatchlist() const;
  void nextTutorialWatchlist(int option);
  void tests();
  void testAddRepo();
  void testDeleteRepo();
  void testUpdateRepo();
  void testDeleteSpecificWatchlis();
  void testAddWatchlist();
  void testDeleteWatchlist();
  void testPlay();
  void testNext();
  void testGet();
};

#endif /* Controller_h */
