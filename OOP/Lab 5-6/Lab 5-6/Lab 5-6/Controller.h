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

class Controller {
private:
  Repository repo;
  // PlayList playList;

public:
  Controller(const Repository &r) : repo{r} {}

  Repository getRepo() const { return repo; }
  // PlayList getPlaylist() const { return playList; }

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
};

#endif /* Controller_h */
