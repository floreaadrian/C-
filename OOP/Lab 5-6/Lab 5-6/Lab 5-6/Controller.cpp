//
//  Controller.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Controller.h"

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

int Controller::updateTutorialToRepository(
    const std::string &presenter, const std::string &title,
    const std::string &newPresenter, const std::string &newTitle,
    double minutes, double seconds, int likes, const std::string &source) {
  Tutorial s{newPresenter, newTitle, Duration{minutes, seconds}, likes, source};
  return this->repo.updateTutorial(presenter, title, s);
}
