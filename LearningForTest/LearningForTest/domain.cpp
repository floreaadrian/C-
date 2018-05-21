//
//  domain.cpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "domain.h"

Domain::Domain(): age(),name(""),id1(){}

Domain::Domain(int age,std::string name,int id){
    this->age=age;
    this->name=name;
    this->id1=id;
}
