//
//  Watchlist.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 4/3/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Filter.h"
#include "RepositoryExceptions.h"
#include "Watchlist.h"
#include <algorithm>
#include <fstream>

using namespace std;

Watchlist::Watchlist() {
  this->current = 0;
  this->currentIn = 0;
}
void Watchlist::add(const Tutorial &song) {
  int pos = findByPresenterAndTitlePos(song.getPresenter(), song.getTitle());
  if (pos == -1)
    this->Tutorials.push_back(song);
}

int Watchlist::deleteTutorial(const Tutorial &e) {
  return deleteTutorialWatchlistNameAndPresenter(e.getPresenter(),
                                                 e.getTitle());
}

void Watchlist::addWatch() {
  this->TutorialInWatch.push_back(this->Tutorials[this->current]);
}

Tutorial Watchlist::getCurrentTutorial(int option) {
  if (option == 1) {
    if (this->current == this->Tutorials.size())
      this->current = 0;
    if (this->Tutorials.empty() == false)
      return this->Tutorials[this->current];
    return Tutorial{};
  } else {
    if (this->currentIn == this->TutorialInWatch.size())
      this->currentIn = 0;
    if (this->TutorialInWatch.empty() == false)
      return this->TutorialInWatch[this->currentIn];
    return Tutorial{};
  }
}

int Watchlist::deleteTutorialWatchlistNameAndPresenter(
    const std::string &presenter, const std::string &title) {
  int pos = findByPresenterAndTitlePos(presenter, title);
  if (pos != -1) {
    for (int i = pos; i < this->TutorialInWatch.size()-1; ++i)
    {this->TutorialInWatch[i] = this->TutorialInWatch[i + 1];
      }
    this->TutorialInWatch.pop_back();
    return 1;
  }
  return 0;
}

void Watchlist::play(int option) {
  if (option == 1) {
    if (this->Tutorials.size() == 0)
      return;
    Tutorial currentTutorial = this->getCurrentTutorial(1);
    currentTutorial.play();
  } else {
    if (this->TutorialInWatch.size() == 0)
      return;
    Tutorial currentTutorial = this->getCurrentTutorial(2);
    currentTutorial.play();
  }
}

Tutorial Watchlist::findByPresenterAndTitle(const std::string &presenter,
                                            const std::string &title) {
  if (this->TutorialInWatch.empty() == true)
    return Tutorial{};
  for (int i = 0; i < this->TutorialInWatch.size(); i++) {
    Tutorial s = this->TutorialInWatch[i];
    if (s.getPresenter() == presenter && s.getTitle() == title)
      return s;
  }

  return Tutorial{};
}

int Watchlist::findByPresenterAndTitlePos(const std::string &presenter,
                                          const std::string &title) {
  if (this->TutorialInWatch.empty() == true)
    return -1;
  for (int i = 0; i < this->TutorialInWatch.size(); i++) {
    Tutorial s = this->TutorialInWatch[i];
    if (s.getPresenter() == presenter && s.getTitle() == title)
      return i;
  }

  return -1;
}

void Watchlist::next(int option) {
  if (option == 1) {
    if (this->Tutorials.empty() == true)
      return;
    this->current = (this->current + 1) % this->Tutorials.size();
    Tutorial currentTutorial = this->getCurrentTutorial(1);
    currentTutorial.play();
  } else {
    if (this->TutorialInWatch.empty() == true)
      return;
    this->currentIn = (this->currentIn + 1) % this->TutorialInWatch.size();
    Tutorial currentTutorial = this->getCurrentTutorial(2);
    currentTutorial.play();
  }
}

bool functie(Tutorial a, Tutorial b) { return a.getTitle() > b.getTitle(); }

std::vector<Tutorial> Watchlist::sorted() {
  // FilterMoreMinutes filterMore;
  // std::cout<<filterMore.include(this->Tutorials[0],this->Tutorials[1]);
  std::vector<Tutorial> sortedTut = this->Tutorials;
  sort(sortedTut.begin(), sortedTut.end(), functie);
  return sortedTut;
}

bool Watchlist::isEmpty() { return this->TutorialInWatch.size() == 0; }


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
  this->sortTest();
}
void Watchlist::addTest() {
  Watchlist watch{};
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  watch.addWatch();
  assert(watch.getTutorials().size() == 2);
  assert(watch.getWatch().size() == 1);
}

void Watchlist::deleteElemTest() {
  Watchlist watch{};
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.addWatch();
  watch.deleteTutorial(s1);
  assert(watch.getWatch().size() == 0);
}
void Watchlist::getCurrentTest() {
  Watchlist watch{};
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  assert(watch.getCurrentTutorial(1) == s1);
  watch.next(1);
  assert(watch.getCurrentTutorial(1) == s2);
}
void Watchlist::getCurrentNumberTest() {
  Watchlist watch{};
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  assert(watch.getCurrentNumber() == 0);
  watch.next(1);
  assert(watch.getCurrentNumber() == 1);
}
void Watchlist::deleteTest() {
  Watchlist watch{};
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.addWatch();
  watch.add(s2);
  watch.next(1);
  watch.addWatch();
  assert(watch.findByPresenterAndTitle("a", "b") == s1);
  assert(watch.deleteTutorialWatchlistNameAndPresenter("a", "b") == 1);
  assert(watch.getWatch().size() == 1);
  assert(watch.findByPresenterAndTitlePos("a", "b") == -1);
  assert(watch.findByPresenterAndTitle("a", "b") == Tutorial{});
}
void Watchlist::playTest() {
  Watchlist watch{};
  watch.play(1);
  watch.play(2);
  assert(getCurrentTutorial(1) == Tutorial{});
  assert(getCurrentTutorial(2) == Tutorial{});
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.addWatch();
  watch.play(1);
  watch.play(2);
  // std::cout << watch.getCurrentNumberIn();
  assert(watch.getCurrentNumber() == 0);
  assert(watch.getCurrentNumberIn() == 0);
}
void Watchlist::nextTest() {
  Watchlist watch{};
  watch.next(1);
  watch.next(2);
  assert(findByPresenterAndTitle("dfs", "fds") == Tutorial{});
  assert(getCurrentTutorial(1) == Tutorial{});
  assert(getCurrentTutorial(2) == Tutorial{});
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.addWatch();
  watch.add(s2);
  watch.next(1);
  watch.addWatch();
  watch.next(2);
  assert(watch.getCurrentNumber() == 1);
  assert(watch.getCurrentNumberIn() == 1);
  watch.next(1);
  watch.next(2);
  assert(watch.getCurrentNumber() == 0);
  assert(watch.getCurrentNumberIn() == 0);
}
void Watchlist::emptyTest() {
  Watchlist watch{};
  assert(watch.isEmpty() == true);
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  watch.addWatch();
  watch.next(1);
  watch.addWatch();
  assert(watch.isEmpty() == false);
  watch.deleteTutorial(s1);
  watch.deleteTutorial(s2);
  assert(watch.isEmpty() == true);
}

void Watchlist::sortTest() {
  Watchlist watch{};
  assert(watch.isEmpty() == true);
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  Tutorial s3{"b", "a", Duration{70, 32}, 0, "https://"};
  watch.add(s1);
  watch.add(s2);
  watch.add(s3);
  std::vector<Tutorial> newOne = watch.sorted();
 // assert(watch.getTutorials()[0].getTitle() == "a");
}
