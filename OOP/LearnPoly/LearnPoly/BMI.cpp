//
//  BMI.cpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "BMI.h"

using namespace std;

bool BMI::isResultOk(){
    if(this->value<30)return true;
    return false;
}

string BMI::toString(){
    string s = "";
    s+= this->date + ",";
    s+= to_string(this->value)+"\n";
    return s;
}
