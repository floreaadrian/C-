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
#include "DynamicArray.h"
#include "Tutorial.h"

class Repository {
private:
  DynamicArray Tutorials;

public:
  /*
   Default constructu=or.
   Initializes an object of type repository.
   */
  Repository() {}

  /*
   Adds a Tutorial to the repository.
   Input: s - Tutorial.
   Output: the Tutorial is added to the repository.
   */
  int addTutorial(const Tutorial &s);
  int deleteTutorial(const std::string &presenter, const std::string &title);
  int updateTutorial(const std::string &presenter, const std::string &title,
                     const Tutorial &s);

  /*
   Finds a Tutorial, by presenter and title.
   Input: presenter, title - string
   Output: the Tutorial that was found, or an "empty" Tutorial (all fields empty
   and duration 0), if nothing was found.
   */
  Tutorial findByPresenterAndTitle(const std::string &presenter,
                                   const std::string &title);
  int findByPresenterAndTitlePos(const std::string &presenter,
                                 const std::string &title);

  DynamicArray getTutorials() const { return Tutorials; }
  void tests();
    void addTest();
    void deleteTest();
    void updateTest();
    void findTest();
};
#endif /* Repo_hpp */
