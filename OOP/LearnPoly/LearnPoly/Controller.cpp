//
//  Controller.cpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Controller.h"

void Controller::add(Medical* a){
    this->p.addAnalysis(a);
}

std::vector<Medical*> Controller::getAll(){
    return this->p.getAll();
}

void Controller::writeToFile(){
    this->p.writeToFile();
}
