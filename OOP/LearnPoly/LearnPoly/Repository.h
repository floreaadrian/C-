//
//  Repository.hpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Repository_h
#define Repository_h

#include <stdio.h>
#include "Person.h"
#include "MedicalAnalysis.h"
#include <vector>

class Repository{
private:
    std::vector<Medical*> data;
    Person p;
public:
    Repository(const Person &pe): p{pe} {}
    
};

#endif /* Repository_hpp */
