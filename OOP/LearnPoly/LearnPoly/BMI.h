//
//  BMI.h
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef BMI_h
#define BMI_h

#include <stdio.h>
#include "MedicalAnalysis.h"

class BMI : public Medical{
private:
    double value;
public:
    BMI(const std::string& dat,const double val):Medical {dat}{this->value=val;}
    bool isResultOk()override;
    std::string toString()override;
};


#endif /* BMI_h */
