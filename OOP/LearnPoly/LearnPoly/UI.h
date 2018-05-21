//
//  UI.hpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef UI_h
#define UI_h

#include <stdio.h>
#include "Controller.h"
#include "BMI.h"
#include "BP.h"
#include "MedicalAnalysis.h"

class UI{
private:
    Controller ctrl;
public:
    UI(const Controller &c) : ctrl(c){}
    void run();
private:
    void printMenu();
};

#endif /* UI_hpp */
