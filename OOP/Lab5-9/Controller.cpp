//
//  Controller.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Controller.h"
#include "Filter.h"
#include "FileWatchlist.h"
#include "CSVWatchlist.h"
#include <assert.h>
#include <vector>

// adds the tutorial to the repository by the tutorial elements
int Controller::addTutorialToRepository(const std::string &presenter,
                                        const std::string &title,
                                        double minutes, double seconds,
                                        int likes, const std::string &source)
{
  Tutorial s{presenter, title, Duration{minutes, seconds}, likes, source};
  this->validator.validate(s);
  return this->repo.addTutorial(s);
}
// deletes the tutorial from repository by presenter and title
int Controller::deleteTutorialToRepository(const std::string &presenter,
                                           const std::string &title)
{
  return this->repo.deleteTutorial(presenter, title);
}
// deletes the tutorial from watchlist by presenter and title
int Controller::deleteTutorialWatchlist(const Tutorial &tutorial)
{
  return this->watchList->deleteTutorial(tutorial);
}
// update the tutorial from repository given the inital presenter and title,and
// change with all thinghs
int Controller::updateTutorialToRepository(
    const std::string &presenter, const std::string &title,
    const std::string &newPresenter, const std::string &newTitle,
    double minutes, double seconds, int likes, const std::string &source)
{
  // Tutorial s{newPresenter, newTitle, Duration{minutes, seconds}, likes,
  // source};
  Tutorial s{newPresenter, newTitle, Duration{minutes, seconds}, likes, source};
  this->validator.validate(s);
  return this->repo.updateTutorial(presenter, title, s);
}

void Controller::write()
{
  this->repo.writeToFile();
  // this->watchList->writeToFile();
}

// deleting a tutorial from watchlist given the name and presenter
int Controller::deleteTutorialWatchlistNameAndPresenterCtrl(
    const std::string &presenter, const std::string &title, bool like)
{
  if (this->watchList->deleteTutorialWatchlistNameAndPresenter(presenter,
                                                               title) == 1)
  {
    if (like == true)
      this->repo.likeTutorial(presenter, title);
    return 1;
  }
  return 0;
}
// adding all the tutorials to a watchlist with a given presenter
void Controller::addAllTutorialsByPresenterToWatchlist(
    const std::string &presenter)
{
  // get all the tutorials from the repository
  std::vector<Tutorial> v = this->repo.getTutorials();
  for (int i = 0; i < v.size(); i++)
  {
    Tutorial s = v[i];
    if (s.getPresenter() == presenter)
    {
      this->watchList->add(s);
    }
  }
}

void Controller::addCurrentWatchlist() { this->watchList->addWatch(); }
// adding all the tutorials to a watchlist
void Controller::addAllTutorialsToWatchlist()
{
  std::vector<Tutorial> v = this->repo.getTutorials();
  for (auto it : v)
  {
    this->watchList->add(it);
  }
}
// playing the current tutorial of the watchlist
void Controller::playWatchlist(int option) { this->watchList->play(option); }

// playing the next tutorial of the watchlist
void Controller::nextTutorialWatchlist(int option)
{
  this->watchList->next(option);
}

std::vector<Tutorial> Controller::sorted() { return this->watchList->sorted(); }

void Controller::saveWatchlist()
{
  if (this->watchList == nullptr)
    return;

  this->watchList->writeToFile();
}

void Controller::openWatchlist() const
{
  if (this->watchList == nullptr)
    return;

  this->watchList->displayWatchlist();
}

//
// // TEEEEESTTTTTSSSSS HUARRAAAAAAYYYYYYYYY

void Controller::tests()
{
  this->testAddRepo();
  this->testDeleteRepo();
  this->testUpdateRepo();
  this->testDeleteSpecificWatchlis();
  this->testAddWatchlist();
  this->testDeleteWatchlist();
  this->testPlay();
  this->testNext();
  this->testGet();
}
void Controller::testAddRepo()
{
  this->addTutorialToRepository("Abc", "abc", 10, 10, 0, "http://");
  assert(this->repo.findByPresenterAndTitlePos("b", "a") == -1);
  assert(this->addTutorialToRepository("BCDA", "abc", 10, 10, 0, "http://") ==
         1);
  this->addTutorialToRepository("ABC", "sdsa", 10, 10, 0, "http://");
  assert(this->addTutorialToRepository("Sds", "dsa", 21, 21, 0, "http://") ==
         1);
  assert(this->addTutorialToRepository("Sds", "dsa", 32, 21, 0, "http://") ==
         0);
  assert(this->repo.getTutorials().size() == 4);
  this->addTutorialToRepository("SDA", "ddd", 10, 10, 0, "http://");
  assert(this->repo.getTutorials().size() == 5);
}
void Controller::testDeleteRepo()
{
  this->addTutorialToRepository("Bca", "abc", 10, 10, 0, "http://");
  assert(this->repo.findByPresenterAndTitlePos("Bca", "abc") != -1);
  assert(this->deleteTutorialToRepository("Bca", "abc") == 1);
  assert(this->repo.findByPresenterAndTitlePos("Bca", "abc") == -1);
  assert(this->deleteTutorialToRepository("Bca", "abc") == 0);
}
void Controller::testUpdateRepo()
{
  this->addTutorialToRepository("A", "abc", 10, 10, 0, "http://");
  assert(this->repo.findByPresenterAndTitlePos("A", "abc") != -1);
  // test if the update succeded
  assert(this->updateTutorialToRepository("A", "abc", "C", "dac", 10, 10, 0,
                                          "http") == 1);
  // if we found the updated tutorial
  assert(this->repo.findByPresenterAndTitlePos("C", "dac") != -1);
  // if we don't find the old tutorial
  assert(this->repo.findByPresenterAndTitlePos("A", "abc") == -1);
  // test if we can update something we don't have
  assert(this->updateTutorialToRepository("b", "a", "A", "dcd", 10, 10, 0,
                                          "http") == 0);
  // test to update with something we already have
  assert(this->updateTutorialToRepository("C", "dac", "C", "dac", 10, 10, 0,
                                          "http") == 0);
}
void Controller::testDeleteSpecificWatchlis()
{
  Tutorial first{"A", "abc", Duration{10, 10}, 0, "http://"};
  this->watchList->add(first);
  addCurrentWatchlist();
  assert(this->watchList->findByPresenterAndTitlePos("A", "abc") != -1);
  assert(this->deleteTutorialWatchlistNameAndPresenterCtrl("A", "abc", true) ==
         1);
  assert(this->deleteTutorialWatchlistNameAndPresenterCtrl("A", "abc", false) ==
         0);
  assert(this->watchList->getWatch().size() == 0);
}
void Controller::testAddWatchlist()
{
  Repository repo{"RepoTest.txt"};
  FileWatchlist *watch = new CSVWatchlist{"WatchTest.txt"};
  this->repo = repo;
  this->watchList = watch;
  addAllTutorialsToWatchlist();
  assert(this->watchList->getTutorials().size() == 0);
  this->addTutorialToRepository("B", "abc", 10, 10, 0, "http://");
  this->addTutorialToRepository("B", "cbc", 10, 10, 0, "http://");
  this->addTutorialToRepository("B", "dbc", 10, 10, 0, "http://");
  this->addTutorialToRepository("B", "ebc", 10, 10, 0, "http://");
  this->addAllTutorialsByPresenterToWatchlist("B");
  assert(this->repo.getTutorials() == this->watchList->getTutorials());
  this->addTutorialToRepository("D", "ebc", 10, 10, 0, "http://");
  this->addAllTutorialsByPresenterToWatchlist("D");
  assert(this->repo.getTutorials() == this->watchList->getTutorials());
  for (int i = 0; i < this->watchList->getTutorials().size(); ++i)
  {
    this->watchList->addWatch();
    this->watchList->next(1);
  }
  this->deleteTutorialWatchlistNameAndPresenterCtrl("B", "abc", false);
  assert((this->repo.getTutorials() == this->watchList->getWatch()) == false);
  addAllTutorialsToWatchlist();
}
void Controller::testDeleteWatchlist()
{
  Repository repo{"RepoTest.txt"};
  FileWatchlist *watch = new CSVWatchlist{"WatchTest.txt"};
  this->repo = repo;
  this->watchList = watch;
  this->addTutorialToRepository("B", "abc", 10, 10, 0, "http://");
  this->addTutorialToRepository("B", "cbc", 10, 10, 0, "http://");
  this->addTutorialToRepository("B", "dbc", 10, 10, 0, "http://");
  Tutorial first{"B", "abc", Duration{10, 10}, 0, "http://"};
  this->addAllTutorialsByPresenterToWatchlist("B");
  this->watchList->addWatch();
  assert(this->deleteTutorialWatchlist(first) == 1);
  assert(this->watchList->getWatch().size() == 0);
}
void Controller::testPlay()
{
  Repository repo{"RepoTest.txt"};
  FileWatchlist *watch = new CSVWatchlist{"WatchTest.txt"};
  this->repo = repo;
  this->watchList = watch;
  this->addTutorialToRepository("B", "abc", 10, 10, 0, "http://");
  this->addTutorialToRepository("B", "cbc", 10, 10, 0, "http://");
  Tutorial first{"B", "abc", Duration{10, 10}, 0, "http://"};
  this->addAllTutorialsByPresenterToWatchlist("B");
  Tutorial old = this->watchList->getCurrentTutorial(1);
  this->playWatchlist(1);
  assert(this->watchList->getCurrentTutorial(1) == old);
}
void Controller::testNext()
{
  Repository repo{"RepoTest.txt"};
  FileWatchlist *watch = new CSVWatchlist{"WatchTest.txt"};
  this->repo = repo;
  this->watchList = watch;
  this->addTutorialToRepository("B", "abc", 10, 10, 0, "http://");
  this->addTutorialToRepository("B", "cbc", 10, 10, 0, "http://");
  Tutorial first{"B", "abc", Duration{10, 10}, 0, "http://"};
  this->addAllTutorialsByPresenterToWatchlist("B");
  Tutorial old = this->watchList->getCurrentTutorial(1);
  this->nextTutorialWatchlist(1);
  assert((this->watchList->getCurrentTutorial(1) == old) == false);
  assert(this->watchList->getCurrentNumber() == 1);
  this->nextTutorialWatchlist(1);
  assert(this->watchList->getCurrentNumber() == 0);
}

void Controller::testGet()
{
  Repository repo{"RepoTest.txt"};
  FileWatchlist *watch = new CSVWatchlist{"WatchTest.txt"};
  this->repo = repo;
  this->watchList = watch;
  Tutorial a{"B", "abc", Duration{10, 10}, 0, "http://"};
  Tutorial b{"B", "cbc", Duration{10, 10}, 0, "http://"};
  this->addTutorialToRepository("B", "abc", 10, 10, 0, "http://");
  this->addTutorialToRepository("B", "cbc", 10, 10, 0, "http://");
  this->addAllTutorialsByPresenterToWatchlist("B");
  std::vector<Tutorial> toComp;
  toComp.push_back(a);
  toComp.push_back(b);
  assert(toComp == getWatchlist()->getTutorials());
  assert(toComp == getRepo().getTutorials());
  std::vector<Tutorial> hei = this->sorted();
}
