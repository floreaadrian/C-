//
//  Controller.hpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Controller_h
#define Controller_h

#include <stdio.h>
#include "Repository.h"

class Controller{
private:
    Person p;
public:
    Controller(const Person &r) : p{r}{}
    void add(Medical *a);
    std::vector<Medical*> getAll();
    void writeToFile();
    
};

#endif /* Controller_hpp */
