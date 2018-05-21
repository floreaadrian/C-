//
//  BP.h
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef BP_h
#define BP_h

#include <stdio.h>
#include <string>
#include "MedicalAnalysis.h"

class BP : public Medical{
private:
    int systolicValue;
    int distolicValue;
public:
    BP(const std::string& dat,const int sys,const int dis):Medical {dat}{this->systolicValue=sys;this->distolicValue=dis;}
    bool isResultOk() override;
    std::string toString() override;
};


#endif /* BP_h */
