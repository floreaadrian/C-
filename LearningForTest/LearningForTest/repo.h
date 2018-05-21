//
//  repo.hpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef repo_h
#define repo_h

#include <stdio.h>
#include <vector>
#include "domain.h"

class Repository{
private:
    std::vector<Domain> data;
public:
    Repository() {};
    int add(int age,std::string name,int id);
    int deleteObj(int id);
    int update(int id,int newAge,std::string newName);
    Domain find(int id);
    int findPos(int id);
    std::vector <Domain> getVectorSorted();
    std::vector <Domain> getData() const {return data;}
};

#endif /* repo_hpp */
