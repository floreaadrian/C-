//
//  controller.cpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "controller.h"

int Controller::add(int age, std::string name, int id){
    return this->repo.add(age,name,id);
}

int Controller::deleteObj(int id){
    return this->repo.deleteObj(id);
}

int Controller::update(int id, int newAge, std::string newName){
    return this->repo.update(id, newAge, newName);
}
