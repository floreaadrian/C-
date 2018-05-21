//
//  MedicalAnalysis.hpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef MedicalAnalysis_h
#define MedicalAnalysis_h

#include <stdio.h>
#include <string>

class Medical{
protected:
    std::string date;
public:
    Medical(const std::string& d);
    virtual ~Medical(){}
    virtual bool isResultOk() = 0;
    virtual std::string toString() = 0;
};

#endif /* MedicalAnalysis_hpp */
