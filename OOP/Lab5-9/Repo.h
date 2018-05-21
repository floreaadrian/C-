//
//  Repo.h
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Repo_h
#define Repo_h

#pragma once
#include "Tutorial.h"
#include <vector>

class Repository {
private:
  std::vector<Tutorial> Tutorials;
  std::string filename;


public:
  /*
   Default constructu=or.
   Initializes an object of type repository.
   */
  Repository(const std::string& filename);

  /*
   Adds a Tutorial to the repository.
   Input: s - Tutorial.
   Output: the Tutorial is added to the repository.
   */
  int addTutorial(const Tutorial &s);
  int deleteTutorial(const std::string &presenter, const std::string &title);
  int updateTutorial(const std::string &presenter, const std::string &title,
                     const Tutorial &s);
  void likeTutorial(const std::string &presenter, const std::string &title);
  std::vector<Tutorial> getTutorials() const { return Tutorials; }
  Tutorial findByPresenterAndTitle(const std::string &presenter,
                                   const std::string &title);
  int findByPresenterAndTitlePos(const std::string &presenter,
                                 const std::string &title);
    void writeToFile();
  void tests();
  void addTest();
  void deleteTest();
  void updateTest();
  void likeTests();

private:
    void readFromFile();

};
#endif /* Repo_hpp */
