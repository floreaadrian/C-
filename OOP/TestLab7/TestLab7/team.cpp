//
//  team.cpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "team.h"

Teams::Teams(): name(""),country(""),score() {}

Teams::Teams(std::string name,std::string country,int score){
    this->name=name;
    this->country = country;
    this->score=score;
}
