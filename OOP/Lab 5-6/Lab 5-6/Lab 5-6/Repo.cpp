//
//  Repo.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Repo.h"
#include <assert.h>
#include <string>

using namespace std;

int Repository::addTutorial(const Tutorial &s) {
  if (this->Tutorials.findByPresenterAndTitlePos(s.getPresenter(),
                                                 s.getTitle()) == -1) {
    if (s.getDuration().getMinutes() > 0 && s.getDuration().getSeconds() < 60 &&
        s.getDuration().getSeconds() > 0) {
      this->Tutorials.add(s);
      return 1;
    }
  }
  return 0;
}

int Repository::deleteTutorial(const std::string &presenter,
                               const std::string &title) {
  if (this->Tutorials.findByPresenterAndTitlePos(presenter, title) != -1) {
    this->Tutorials = this->Tutorials -
                      this->Tutorials.findByPresenterAndTitle(presenter, title);
    return 1;
  }
  return 0;
}

void Repository::likeTutorial(const std::string &presenter,
                              const std::string &title) {
  int pos = this->Tutorials.findByPresenterAndTitlePos(presenter, title);
  Tutorial s = this->Tutorials.findByPresenterAndTitle(presenter, title);
  s.upLike();
  Tutorial *TutorialsInDynamicArray = this->Tutorials.getAllElems();
  TutorialsInDynamicArray[pos] = s;
}

int Repository::updateTutorial(const std::string &presenter,
                               const std::string &title, const Tutorial &s) {
  int pos = this->Tutorials.findByPresenterAndTitlePos(presenter, title);
  if (pos != -1) {
    if (this->Tutorials.findByPresenterAndTitlePos(s.getPresenter(),
                                                   s.getTitle()) == -1) {
      Tutorial *TutorialsInDynamicArray = this->Tutorials.getAllElems();
      TutorialsInDynamicArray[pos] = s;
      return 1;
    }
  }
  return 0;
}

void Repository::tests() {
  addTest();
  deleteTest();
  updateTest();
  likeTests();
}

void Repository::addTest() {
  Repository repo;
  Tutorial s1{"Derek Banas", "C++ Programming", Duration{70, 32}, 0,
              "https://www.youtube.com/watch?v=Rub-JsjMhWY"};
  Tutorial s2{
      "Gleesik ", "#01 Tutorial C++ |Introducere +Visual Studio |Gleesik™",
      Duration{14, 6}, 0, "https://www.youtube.com/watch?v=lAvIuQIhbOQ"};
  Tutorial s3{"TheChernoProject", "How C++ Works", Duration{20, 20}, 0,
              "https://www.youtube.com/watch?v=SfGuIVzE_Os"};
  Tutorial s4{"Easy Programming", "C++ Tutorials From Basic to Advance",
              Duration{553, 4}, 0,
              "https://www.youtube.com/watch?v=mUQZ1qmKlLY"};
  repo.addTutorial(s1);
  repo.addTutorial(s2);
  repo.addTutorial(s3);
  assert(repo.getTutorials().getSize() == 3);
  repo.addTutorial(s3);
  assert(repo.getTutorials().getSize() == 3);
  repo.addTutorial(s4);
  assert(repo.getTutorials().getSize() == 4);
}

void Repository::deleteTest() {
  Repository repo;
  Tutorial s1{"Derek Banas", "C++ Programming", Duration{70, 32}, 0,
              "https://www.youtube.com/watch?v=Rub-JsjMhWY"};
  Tutorial s2{
      "Gleesik ", "#01 Tutorial C++ |Introducere +Visual Studio |Gleesik™",
      Duration{14, 6}, 0, "https://www.youtube.com/watch?v=lAvIuQIhbOQ"};
  Tutorial s3{"TheChernoProject", "How C++ Works", Duration{20, 20}, 0,
              "https://www.youtube.com/watch?v=SfGuIVzE_Os"};
  repo.addTutorial(s1);
  repo.addTutorial(s2);
  repo.addTutorial(s3);
  repo.deleteTutorial("Derek Banas", "C++ Programming");
  assert(repo.getTutorials().getSize() == 2);
  repo.deleteTutorial("Derek Banas", "C++ Programming");
  assert(repo.getTutorials().getSize() == 2);
}

void Repository::updateTest() {
  Repository repo;
  Tutorial s1{"Derek Banas", "C++ Programming", Duration{70, 32}, 0,
              "https://www.youtube.com/watch?v=Rub-JsjMhWY"};
  Tutorial s2{
      "Gleesik ", "#01 Tutorial C++ |Introducere +Visual Studio |Gleesik™",
      Duration{14, 6}, 0, "https://www.youtube.com/watch?v=lAvIuQIhbOQ"};
  Tutorial s3{"TheChernoProject", "How C++ Works", Duration{20, 20}, 0,
              "https://www.youtube.com/watch?v=SfGuIVzE_Os"};
  repo.addTutorial(s1);
  repo.addTutorial(s2);
  repo.addTutorial(s3);
  Tutorial u1{"a", "b", Duration{2, 2}, 0, "http"};
  repo.updateTutorial("Derek Banas", "C++ Programming", u1);
  assert(this->Tutorials.findByPresenterAndTitlePos("Derek Banas",
                                                    "C++ Programming") == -1);
}
void Repository::likeTests() {
  Repository repo;
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  repo.addTutorial(s1);
  repo.addTutorial(s2);
  repo.likeTutorial("a", "b");
  assert(repo.getTutorials().findByPresenterAndTitle("a", "b").getLikes() == 1);
}
