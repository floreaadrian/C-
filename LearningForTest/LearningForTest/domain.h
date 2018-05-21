//
//  domain.hpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef domain_h
#define domain_h

#include <stdio.h>
#include <string>

class Domain{

private:
    int age;
    std::string name;
    int id1;
public:
    Domain();
    Domain(int age,std::string name,int id1);
    int getId() const {return id1;}
    int getAge() const {return age;}
    void setName(std::string newName)  {name=newName;}
    void setAge(int newAge){age=newAge;}
    std::string getName()const {return name;}
};

#endif /* domain_hpp */
