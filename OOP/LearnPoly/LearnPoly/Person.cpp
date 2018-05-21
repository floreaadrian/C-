//
//  Person.cpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Person.h"
#include <fstream>

using namespace std;

Person::Person(const std::string& n){
    this->name = n;
}

std::vector<Medical*> Person::getAll(){
    return this->data;
}

void Person::addAnalysis(Medical* a){
    this->data.push_back(a);
}

void Person::writeToFile(){
    ofstream fout("data.out");
    for(auto it: this->data)
        fout<<it->toString();
    fout.close();
}
