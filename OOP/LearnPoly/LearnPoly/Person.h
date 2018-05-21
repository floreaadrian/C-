//
//  Person.h
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Person_h
#define Person_h

#include <stdio.h>
#include <string>
#include <vector>

#include "MedicalAnalysis.h"

class Person{
private:
    std::string name;
    std::vector<Medical*> data;
public:
    Person(const std::string& n);
    void addAnalysis(Medical* a);
    std::vector<Medical*> getAll();
    void writeToFile();
};


#endif /* Person_h */
