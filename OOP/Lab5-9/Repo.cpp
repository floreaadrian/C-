//
//  Repo.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Repo.h"
#include "RepositoryExceptions.h"
#include <assert.h>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

Repository::Repository(const std::string &filename)
{
  this->filename = filename;
  this->readFromFile();
}

int Repository::addTutorial(const Tutorial &s)
{
  if (findByPresenterAndTitlePos(s.getPresenter(), s.getTitle()) == -1)
  {
    if (s.getDuration().getMinutes() > 0 && s.getDuration().getSeconds() < 60 &&
        s.getDuration().getSeconds() > 0)
    {
      this->Tutorials.push_back(s);
      return 1;
    }
    return 0;
  }
  return 0;
}

int Repository::deleteTutorial(const std::string &presenter,
                               const std::string &title)
{
  int pos = findByPresenterAndTitlePos(presenter, title);
  if (pos != -1)
  {
    for (int i = pos; i < this->Tutorials.size() - 1; ++i)
      this->Tutorials[i] = this->Tutorials[i + 1];
    this->Tutorials.pop_back();
    return 1;
  }
  return 0;
}

void Repository::likeTutorial(const std::string &presenter,
                              const std::string &title)
{
  int pos = findByPresenterAndTitlePos(presenter, title);
  Tutorial s = findByPresenterAndTitle(presenter, title);
  s.upLike();
  // Tutorial *TutorialsInDynamicArray = this->Tutorials.getAllElems();
  this->Tutorials[pos] = s;
}

Tutorial Repository::findByPresenterAndTitle(const std::string &presenter,
                                             const std::string &title)
{

  size_t size = std::count_if(this->Tutorials.begin(), this->Tutorials.end(), [presenter, title](Tutorial &a) { return a.getPresenter() == presenter && a.getTitle() == title; });
  std::vector<Tutorial> result{size};
  auto it = std::copy_if(this->Tutorials.begin(), this->Tutorials.end(), result.begin(), [presenter, title](Tutorial &a) { return a.getPresenter() == presenter && a.getTitle() == title; });
  if (result.empty() == true)
    return Tutorial{};
  return result[0];
}

int Repository::findByPresenterAndTitlePos(const std::string &presenter,
                                           const std::string &title)
{

  if (this->Tutorials.size() == 0)
    return -1;
  for (int i = 0; i < this->Tutorials.size(); i++)
  {
    Tutorial s = this->Tutorials[i];
    if (s.getPresenter() == presenter && s.getTitle() == title)
      return i;
  }
  return -1;
}

int Repository::updateTutorial(const std::string &presenter,
                               const std::string &title, const Tutorial &s)
{
  int pos = findByPresenterAndTitlePos(presenter, title);
  if (pos != -1)
  {
    if (findByPresenterAndTitlePos(s.getPresenter(), s.getTitle()) == -1)
    {
      this->Tutorials[pos] = s;
      return 1;
    }
  }
  return 0;
}

void Repository::readFromFile()
{
  ifstream file(this->filename);

  if (!file.is_open())
    throw FileException("The file could not be opened!");

  Tutorial s;
  while (file >> s)
    this->Tutorials.push_back(s);

  file.close();
}

void Repository::writeToFile()
{
  ofstream file(this->filename);
  if (!file.is_open())
    throw FileException("The file could not be opened!");

  for (auto s : this->Tutorials)
  {
    file << s;
  }

  file.close();
}

// tests

void Repository::tests()
{
  addTest();
  deleteTest();
  updateTest();
  likeTests();
}

void Repository::addTest()
{
  Repository repo{this->filename};
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
  Tutorial s5{"a", "b", Duration{32, 70}, 0, "http://"};
  repo.addTutorial(s1);
  repo.addTutorial(s2);
  repo.addTutorial(s3);
  repo.addTutorial(s5);
  assert(repo.getTutorials().size() == 3);
  repo.addTutorial(s3);
  assert(repo.getTutorials().size() == 3);
  repo.addTutorial(s4);
  assert(repo.getTutorials().size() == 4);
}

void Repository::deleteTest()
{
  Repository repo{this->filename};
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
  assert(repo.getTutorials().size() == 2);
  repo.deleteTutorial("Derek Banas", "C++ Programming");
  assert(repo.getTutorials().size() == 2);
}

void Repository::updateTest()
{
  Repository repo{this->filename};
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
  assert(repo.findByPresenterAndTitlePos("Derek Banas", "C++ Programming") ==
         -1);
  //std::cout<<repo.findByPresenterAndTitle("aa", "b");
  assert(repo.findByPresenterAndTitle("aa", "b") == Tutorial{});
}
void Repository::likeTests()
{
  Repository repo{this->filename};
  Tutorial s1{"a", "b", Duration{70, 32}, 0, "https://"};
  Tutorial s2{"b", "c", Duration{70, 32}, 0, "https://"};
  assert(repo.findByPresenterAndTitle("b", "c").getLikes() == 0);
  repo.addTutorial(s1);
  repo.addTutorial(s2);
  repo.likeTutorial("a", "b");
  assert(repo.findByPresenterAndTitle("a", "b").getLikes() == 1);
  assert(repo.findByPresenterAndTitle("b", "c").getLikes() == 0);
}
