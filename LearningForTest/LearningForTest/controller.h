//
//  controller.hpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef controller_h
#define controller_h

#include <stdio.h>
#include "repo.h"
class Controller{

private:
    Repository repo;
public:
    Controller(const Repository &r) : repo{r} {}
    int add(int age,std::string name,int id);
    int deleteObj(int id);
    int update(int id,int newAge,std::string newName);
    Repository getRepo(){return repo;}
};

#endif /* controller_hpp */
