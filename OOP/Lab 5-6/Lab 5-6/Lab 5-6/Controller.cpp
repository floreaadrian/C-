//
//  Controller.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Controller.h"
#include <assert.h>

int Controller::addTutorialToRepository(const std::string &presenter,
                                        const std::string &title,
                                        double minutes, double seconds,
                                        int likes, const std::string &source) {
  Tutorial s{presenter, title, Duration{minutes, seconds}, likes, source};
  return this->repo.addTutorial(s);
}

int Controller::deleteTutorialToRepository(const std::string &presenter,
                                           const std::string &title) {
  return this->repo.deleteTutorial(presenter, title);
}

int Controller::deleteTutorialWatchlist(const Tutorial &tutorial) {
  return this->watchList.deleteTutorial(tutorial);
}

int Controller::updateTutorialToRepository(
    const std::string &presenter, const std::string &title,
    const std::string &newPresenter, const std::string &newTitle,
    double minutes, double seconds, int likes, const std::string &source) {
  Tutorial s{newPresenter, newTitle, Duration{minutes, seconds}, likes, source};
  return this->repo.updateTutorial(presenter, title, s);
}

int Controller::deleteTutorialWatchlistNameAndPresenterCtrl(
    const std::string &presenter, const std::string &title, bool like) {
  if (this->watchList.deleteTutorialWatchlistNameAndPresenter(presenter,
                                                              title) == 1) {
    if (like == true)
      this->repo.likeTutorial(presenter, title);
    return 1;
  }
  return 0;
}

void Controller::addAllTutorialsByPresenterToWatchlist(
    const std::string &presenter) {
  // get all the tutorials from the repository
  DynamicArray v = this->repo.getTutorials();
  Tutorial *tutorials = v.getAllElems();
  for (int i = 0; i < v.getSize(); i++) {
    Tutorial s = tutorials[i];
    if (s.getPresenter() == presenter)
      this->watchList.add(s);
  }
}

void Controller::playWatchlist() { this->watchList.play(); }

void Controller::nextTutorialWatchlist() { this->watchList.next(); }

// TEEEEESTTTTTSSSSS HUARRAAAAAAYYYYYYYYY
void Controller::tests() {
  this->testAddRepo();
  this->testDeleteRepo();
  this->testUpdateRepo();
  this->testDeleteSpecificWatchlis();
  this->testAddWatchlist();
  this->testDeleteWatchlist();
  this->testPlay();
  this->testNext();
}
void Controller::testAddRepo() {
  this->addTutorialToRepository("b", "a", 10, 10, 0, "http://");
  assert(this->repo.getTutorials().findByPresenterAndTitlePos("b", "a") != -1);
  assert(this->addTutorialToRepository("b", "a", 10, 10, 0, "http://") == 0);
  this->addTutorialToRepository("c", "s", 10, 10, 0, "http://");
  assert(this->addTutorialToRepository("sds", "ds", -1, -1, 0, "http://") == 0);
  assert(this->addTutorialToRepository("sds", "ds", 32, -1, 0, "http://") == 0);
  assert(this->repo.getTutorials().getSize() == 2);
  this->addTutorialToRepository("d", "ddd", 10, 10, 0, "http://");
  assert(this->repo.getTutorials().getSize() == 3);
}
void Controller::testDeleteRepo() {
  this->addTutorialToRepository("b", "a", 10, 10, 0, "http://");
  assert(this->repo.getTutorials().findByPresenterAndTitlePos("b", "a") != -1);
  assert(this->deleteTutorialToRepository("b", "a") == 1);
  assert(this->repo.getTutorials().findByPresenterAndTitlePos("b", "a") == -1);
  assert(this->deleteTutorialToRepository("b", "a") == 0);
}
void Controller::testUpdateRepo() {
  this->addTutorialToRepository("b", "a", 10, 10, 0, "http://");
  assert(this->repo.getTutorials().findByPresenterAndTitlePos("b", "a") != -1);
  // test if the update succeded
  assert(this->updateTutorialToRepository("b", "a", "c", "d", 10, 10, 0,
                                          "http") == 1);
  // if we found the updated tutorial
  assert(this->repo.getTutorials().findByPresenterAndTitlePos("c", "d") != -1);
  // if we don't find the old tutorial
  assert(this->repo.getTutorials().findByPresenterAndTitlePos("a", "b") == -1);
  // test if we can update something we don't have
  assert(this->updateTutorialToRepository("b", "a", "c", "d", 10, 10, 0,
                                          "http") == 0);
  // test to update with something we already have
  assert(this->updateTutorialToRepository("c", "d", "c", "d", 10, 10, 0,
                                          "http") == 0);
}
void Controller::testDeleteSpecificWatchlis() {
  Tutorial first{"b", "a", Duration{10, 10}, 0, "http://"};
  this->watchList.add(first);
  assert(this->watchList.getTutorials().findByPresenterAndTitlePos("b", "a") !=
         -1);
  assert(this->deleteTutorialWatchlistNameAndPresenterCtrl("b", "a", false) ==
         1);
  assert(this->deleteTutorialWatchlistNameAndPresenterCtrl("b", "a", false) ==
         0);
  assert(this->watchList.getTutorials().getSize() == 0);
}
void Controller::testAddWatchlist() {
  Repository repo;
  this->repo = repo;
  this->addTutorialToRepository("b", "a", 10, 10, 0, "http://");
  this->addTutorialToRepository("b", "c", 10, 10, 0, "http://");
  this->addTutorialToRepository("b", "d", 10, 10, 0, "http://");
  this->addTutorialToRepository("b", "e", 10, 10, 0, "http://");
  this->addAllTutorialsByPresenterToWatchlist("b");
  assert(this->repo.getTutorials() == this->watchList.getTutorials());
  this->addTutorialToRepository("d", "e", 10, 10, 0, "http://");
  this->addAllTutorialsByPresenterToWatchlist("d");
  assert(this->repo.getTutorials() == this->watchList.getTutorials());
  this->deleteTutorialWatchlistNameAndPresenterCtrl("b", "a", false);

  assert((this->repo.getTutorials() == this->watchList.getTutorials()) ==
         false);
}
void Controller::testDeleteWatchlist() {
  Repository repo;
  Watchlist wathc;
  this->watchList = wathc;
  this->repo = repo;
  this->addTutorialToRepository("b", "a", 10, 10, 0, "http://");
  this->addTutorialToRepository("b", "c", 10, 10, 0, "http://");
  this->addTutorialToRepository("b", "d", 10, 10, 0, "http://");
  Tutorial first{"b", "a", Duration{10, 10}, 0, "http://"};
  this->addAllTutorialsByPresenterToWatchlist("b");
  assert(this->deleteTutorialWatchlist(first) == 1);
  assert(this->watchList.getTutorials().getSize() == 2);
}
void Controller::testPlay() {
  Repository repo;
  Watchlist wathc;
  this->watchList = wathc;
  this->repo = repo;
  this->addTutorialToRepository("b", "a", 10, 10, 0, "http://");
  this->addTutorialToRepository("b", "c", 10, 10, 0, "http://");
  Tutorial first{"b", "a", Duration{10, 10}, 0, "http://"};
  this->addAllTutorialsByPresenterToWatchlist("b");
  Tutorial old = this->watchList.getCurrentTutorial();
  this->playWatchlist();
  assert(this->watchList.getCurrentTutorial() == old);
}
void Controller::testNext() {
  Repository repo;
  Watchlist wathc;
  this->watchList = wathc;
  this->repo = repo;
  this->addTutorialToRepository("b", "a", 10, 10, 0, "http://");
  this->addTutorialToRepository("b", "c", 10, 10, 0, "http://");
  Tutorial first{"b", "a", Duration{10, 10}, 0, "http://"};
  this->addAllTutorialsByPresenterToWatchlist("b");
  Tutorial old = this->watchList.getCurrentTutorial();
  this->nextTutorialWatchlist();
  assert((this->watchList.getCurrentTutorial() == old) == false);
  assert(this->watchList.getCurrentNumber() == 1);
  this->nextTutorialWatchlist();
  assert(this->watchList.getCurrentNumber() == 0);
}
