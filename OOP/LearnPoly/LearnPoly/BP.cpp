//
//  BP.cpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "BP.h"

using namespace std;

bool BP::isResultOk(){
    if(this->systolicValue<30 && this->distolicValue>30)return true;
    return false;
}

string BP::toString(){
    string s = "";
    s+= this->date + ",";
    s+= to_string(this->systolicValue) + ",";
    s+= to_string(this->distolicValue) + "\n";
    return s;
}
